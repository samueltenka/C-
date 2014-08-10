#include "List.h"

#ifndef TREE
#define TREE
template<typename T>
class Tree {
	T* value;
	List<Tree<T>> children;
};
#endif
