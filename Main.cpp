#include "Includes.h"
#include "String.h"
#include "List.h"
#include "Tree.h"

// REMEMBER: always input __pointers__ to these processing functions, so that the objects' contents aren't deleted (twice!)
void lex(String* str, List<char>* token_list) {
	// right now, empty shell:
	// TODO: skip whitespace, allow multichar tokens
	for(int i = 0; i < str->length; i++) {
		token_list->append(str->get(i));
	}
}

enum token_type {
	num,
	var,
	plus_sign,
	times_sign,
	open_par,
	close_par,

	unit,
	factors,
	terms
};
bool is_num(char c) {
	return '0'<=c && c<='9';
}
bool is_var(char c) {
	return 'a'<=c && c<='z'; // lowercase alphas
}
void match(LAnt<char>* token_stream, char theory) {
	char experiment = token_stream->march();
	if(experiment != theory) {
		ERROR("expected '%c', but got '%c'", theory, experiment);
	}
}
void match_num(LAnt<char>* token_stream, TAnt<token_type>* ptree_ant) {
	char num = token_stream->march();
	if(!is_num(num)) {
		ERROR("expected digit; instead got '%c'.", num);
	}
}
void match_var(LAnt<char>* token_stream, Tree<token_type>* ptree_ant) {
	char var = token_stream->march();
	if(!is_var(var)) {
		ERROR("expected letter; instead got '%c'.", var);
	}
}

void main() {
	String S("12345");
	List<char> L;
	lex(&S, &L);
}
