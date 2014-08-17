#ifndef TREE
#define TREE

#include "Includes.h"

template <typename X>
struct TNode {
	X val;
	TNode<X>* parent;
	TNode<X>* next;
	TNode<X>* youngest;

	void init() {
		parent = NULL;
		next = NULL;
		youngest = NULL;
	}
	TNode() {
		init();
	}
	TNode(X v) {
		init();
		val = v;
	}
	bool is_root() {
		return parent==NULL;
	}
	bool is_end() {
		return next==NULL;
	}
	bool is_leaf() {
		return youngest==NULL;
	}

	X chop() {
		if(firstborn->is_end()) {
			ERROR("can't chop TNode's children, since no children");
		}
		X v = youngest->val;
		LNode<X>* new_y = youngest->next;
		delete youngest;
		youngest = new_y;
		return v;
	}
	~TNode() {
		while(!youngest->is_end()) {
			chop(); // crazily inefficient, but don't want to write specialized pointer dance.
		}
		delete youngest;
	}
};


template <typename X>
struct Tree {
	//                                r*
	//                                 |
	//     A                           A-->*
	//    / \                          |
	//   B   C     represented as:     B-->C-->*
	//      /|\     /middle vert.s\    |   |
	//     D E F    \bidirectional/    *   D-->E-->F-->*
	//                                     |   |   |
	//                                     *   *   *
	//                             "lastborn"----->"firstborn"

	TNode<X>* root;
	Tree() {
		root = new TNode<X>;
	}
	~Tree() {
		delete root;
	}
};

template <typename X>
struct TAnt { // tree iterator
	TNode<X>* current;

	TAnt(Tree<X>* T) {
		current = T->root;
	}
	bool at_root() {
		return current->is_root();
	}
	bool at_end() {
		return current->is_end();
	}
	bool at_leaf() {
		return current->is_leaf();
	}
	X val() {
		return current->val;
	}
	void rise() {
		current = current->parent;
	}
	void march() {
		current = current->next;
	}
	void descend() {
		current = current->youngest;
	}

	void insert(X v) {
		TNode<X>* baby = new TNode<X>(v);
		baby->parent = current;
		baby->next = current->youngest;
		current->youngest = baby;
	}
};

#endif
