#include "List.h"
#include "Tree.h"
#include "ParseLabels.h"


bool is_num(char c) {
	return ('0'<=c) && (c<='9');
}
bool is_var(char c) {
	return ('a'<=c) && (c<='z'); // lowercase alphas
}

struct Parser {
	LAnt<char>* token_stream;
	Tree<parse_labels>* ptree;
	TAnt<parse_labels>* ptree_ant;

	Parser(List<char>* token_list) {
		token_stream = new LAnt<char>(token_list);
		ptree = new Tree<parse_labels>;
		ptree_ant = new TAnt<parse_labels>(ptree);
	}
	~Parser() {
		delete token_stream;
		delete ptree;
		delete ptree_ant;
	}

	void match(char theory) {
		char experiment = token_stream->march();
		if(experiment != theory) {
			ERROR("expected '%c', but got '%c'", theory, experiment);
		}
	}
	void label(parse_labels l) {
		ptree_ant->set(l);
	}
	void sink() {
		STATUS("SINKING!");
		ptree_ant->sink();
	}
	void rise() {
		STATUS("_RISING!");
		ptree_ant->rise();
	}

	void match_num() {
		STATUS("match_num");
		char c = token_stream->val();
		if(is_num(c)) {
			label(parse_labels::num);
			match(c);
		} else {
			ERROR("expected digit; instead got '%c'.", num);
		}
	}
	void match_var() {
		STATUS("match_var");
		char c = token_stream->val();
		if(is_var(c)) {
			label(parse_labels::var);
			match(c);

		} else {
			ERROR("expected letter; instead got '%c'.", var);
		}
	}
	void match_unit() {
		STATUS("match_unit");
		char c = token_stream->val();
		if(is_num(c)) {
			STATUS("\t attempt num");
			label(parse_labels::unit);
			sink();
			match_num();
			rise();
		} else if(is_var(c)) {
			STATUS("\t attempt var");
			label(parse_labels::unit);
			sink();
			match_var();
			rise();
		} else if(c=='(') {
			STATUS("\t attempt (terms)");
			label(parse_labels::unit);
			sink();
			match('(');
			match_terms();
			match(')');
			rise();
		} else {
			ERROR("expected beginning of unit; instead, got '%c'", c);
		}
	}
	void match_factors() {
		STATUS("match_factors");
		label(parse_labels::factors);
		sink();
		match_unit();
		if(!token_stream->at_end()) {
			char c = token_stream->val();
			if(c=='*') {
				match('*');
				match_factors();
			}
		}
		rise();
	}
	void match_terms() {
		STATUS("match_terms");
		label(parse_labels::terms);
		sink();
		match_factors();
		if(!token_stream->at_end()) {
			char c = token_stream->val();
			if(c=='+') {
				match('+');
				match_terms();
			}
		}
		rise();
	}
};
