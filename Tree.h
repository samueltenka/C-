#ifndef TREE
#define TREE

#include "Includes.h"

template <typename X>
struct TNode {
	X val;
	TNode<X>* parent;
	TNode<X>* next;
	TNode<X>* youngest; // chldr_start, chldr_end

	TNode() {
		parent = NULL;
		next = NULL;
		youngest = NULL;
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
		if(is_leaf()) {
			ERROR("can't chop TNode's children, since no children");
		}
		X v = youngest->val;
		TNode<X>* new_y = youngest->next;
		delete youngest;
		youngest = new_y;
		return v;
	}
	~TNode() {
		while(youngest != NULL) {
			chop(); // crazily inefficient, but don't want to write specialized pointer dance.
		}
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
		if(at_root()) {
			ERROR("can't rise above root!");
		}
		current = current->parent;
	}
	void march() {
		if(at_end()) {
			TNode<X>* baby = new TNode<X>;
			baby->parent = current->parent;
			current->next = baby;
		}
		current = current->next;
	}
	void sink() {
		if(at_leaf()) {
			TNode<X>* baby = new TNode<X>;
			baby->parent = current;
			baby->next = current->youngest;
			current->youngest = baby;
		}
		current = current->youngest;
	}

	void set(X v) {
		current->val = v;
	}
};

#endif
