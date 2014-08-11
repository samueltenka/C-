//
// Linked List:

#ifndef LIST
#define LIST
#include <cstdlib>

//
// Node:
template <typename T>
struct LNode {
	T val;
	LNode<T>* prev;
	LNode<T>* next;
	LNode(): prev(NULL), next(NULL) {}
};

//
// Main Class:
template <typename T>
class List {
	template <typename S>
	friend class LIterator;
private:
	LNode<T>* start;
	LNode<T>* end;
public:
	List();

	bool is_empty();

	void append(T val);
	void chop();
	~List();
};

//
// Iterator:
template <typename T>
class LIterator {
private:
	LNode<T>* current;
public:
	LIterator(const List<T>& L);
	bool can_continue();
	T val();
	void next();

	T remove();
	void insert(T value);
};


//
// Helper function:
template <typename T>
bool List<T>::is_empty() {
	return start==end;
}

//
// Constructor:
template <typename T>
List<T>::List() {
	start = end = new LNode<T>; // TODO: should use initializer list
}

//
// Append / Chop, and Destructor:
template <typename T>
void List<T>::append(T val) { // Mechanics of "[1, 2, 4].append(8)":
								// s1<-->2<-->4<-->e
	end->val = val;				// s1<-->2<-->4<-->e8
	end->next = new LNode<T>;	// s1<-->2<-->4<-->e8 -->
	end->next->prev = end;		// s1<-->2<-->4<-->e8<-->
	end = end->next;			// s1<-->2<-->4<--> 8<-->e
}
template<typename T>
void List<T>::chop() {
	LNode<T>* neighbor = start->next;
	delete start;
	neighbor->prev = NULL;
	start = neighbor;
}
template <typename T>
List<T>::~List() {
	while(!is_empty()) {
		chop();
	}
}


//
// Iteration:
template <typename T>
LIterator<T>::LIterator(const List<T>& L) {
	current = L.start;
}
template <typename T>
bool LIterator<T>::can_continue() {
	return current->next != NULL;
}
template <typename T>
T LIterator<T>::val() {
	return current->val;
}
template <typename T>
void LIterator<T>::next() {
	current = current->next;
}

//
// Remove / Insert at iterator:
//
// NOTE that remove/insert commute:
// [4, 5*, 6].remove() ---> [4*, 6]
// [4*, 6].insert(5) ---> [4, 5*, 6]
template <typename T>
T LIterator<T>::remove() { // doesn't work if current== start or end.
	current->next->prev = current->prev;
	current->prev->next = current->next;

	// TODO: use val(), back(); don't reinvent the wheel:
	T old_val = current->val;
	LNode<T>* delete_me = current;
	current = current->prev;
	delete delete_me;
	return old_val;
}
template <typename T>
void LIterator<T>::insert(T value) {
	LNode<T>* insert_me = new LNode<T>;
	insert_me->val = value;
	insert_me->next = current->next;
	insert_me->prev = current;

	current->next->prev = insert_me;
	current->next = insert_me;

	// TODO: use next(); don't reinvent the wheel:
	current = current->next;
}


#endif
