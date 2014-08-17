#include "String.h"
#include "List.h"


struct Lexer {
	String* str;
	List<char>* token_list;

	Lexer(String* s) {
		str = s;
		token_list = new List<char>;
	}
	~Lexer() {
		delete token_list;
	}

	void lex() {
		// right now, empty shell:
		// TODO: skip whitespace, allow multichar tokens
		for(int i = 0; i < str->length; i++) {
			token_list->append(str->get(i));
		}
	}
};
