#include "List.h"
#include "Tree.h"
#include "Token.h"

#ifndef PARSER
#define PARSER
Tree<Token> parse(List<Token> code);
#endif
