#include "Includes.h"
#include "Lexer.h"
#include "Parser.h"


void main() {
	String S("(b+6)*a");
	Lexer L(&S);
	L.lex();

	LAnt<char> I(L.token_list);
	while(!I.at_end()) {
		printf("...%c\n", I.march());
	}

	Parser P(L.token_list);
	P.match_terms();
}
