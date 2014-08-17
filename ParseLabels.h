#ifndef PARSE_LABELS
#define PARSE_LABELS

enum parse_labels {
	num, var, 
	unit,
	factors,
	terms
};

char names[5][100] = {"num", "var", "unit", "factors", "terms"};

#endif
