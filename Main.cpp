#include "Includes.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>

void print_spaces(int how_many) {
	for(int i= 0; i < how_many; i++) {
		printf(" ");
	}
}
void print(int offset, TNode<parse_labels>* T) {
	if(0<=T->val && T->val<5) {
		print_spaces(offset);
		printf("%s\n", names[T->val]);
		for(TNode<parse_labels>* child = T->youngest; child!=NULL; child=child->next) {
			print(offset+1, child);
		}
	}
}

void main() {
	String S("(a+b)*6");
	Lexer L(&S);
	L.lex();

	LAnt<char> I(L.token_list);
	while(!I.at_end()) {
		printf("...%c\n", I.march());
	}

	Parser P(L.token_list);
	P.match_terms();
	print(0, P.ptree->root);

	PAUSE;
}
