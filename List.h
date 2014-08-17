#ifndef LIST
#define LIST

#include "Includes.h"

template <typename X>
struct LNode {
	X val;
	LNode<X>* next;

	LNode() {
		next = NULL;
	}
	bool is_end() {
		return next==NULL;
	}
};

template <typename X>
struct List {
	// [] represented as:		se --> *
	// [0] represented as:		s0 --> e --> *
	// [0, 1] represented as:	s0 --> 1 --> e --> *
	LNode<X>* start;
	LNode<X>* end;

	List() {
		start = end = new LNode<X>;
	}
	void append(X v) {
		end->val = v;
		end->next = new LNode<X>;
		end = end->next;
	}
	X chop() {
		if(start->is_end()) {
			ERROR("can't chop List, since empty");
		}
		X v = start->val;
		LNode<X>* new_start = start->next;
		delete start;
		start = new_start;
		return v;
	}
	~List() {
		while(!start->is_end()) {
			chop(); // crazily inefficient, but don't want to write specialized pointer dance.
		}
		delete end;
	}
};

template <typename X>
struct LAnt { // a list iterator
	LNode<X>* current;

	LAnt(List<X>* L) {
		current = L->start;
	}
	bool at_end() {
		return current->is_end();
	}
	X val() {
		return current->val;
	}
	X peek() {
		return current->next->val;
	}
	X march() {
		X v = val();
		current = current->next;
		return v;
	}
};

#endif
