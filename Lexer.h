#include "String.h"
#include "List.h"
#include "Token.h"

#ifndef LEXER
#define LEXER
List<Token> lex(String code);
#endif
