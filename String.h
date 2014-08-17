#ifndef STRING
#define STRING

#include "Includes.h"

struct String {
	int length, size;
	char* data;
	
	void init() {
		length = 0;
		data = new char[1];
		size = 1;
	}

	String() {
		init();
	}
	String(const char* chr_str) {
		init();
		for(int i = 0; chr_str[i]!='\0'; i++) {
			set(i, chr_str[i]);
		}
	}

	void set(int i, char c) {
		// expands if out of bounds
		while(size <= i) {
			expand(size*2);
		}
		data[i] = c;
		// following does "while(length <= i) {length++;}":
		if(length <= i) {
			length = i+1;
		}
	}
	char get(int i) {
		if(i < length)
			return data[i];
		ERROR("string index out of range");
	}

	void expand(int new_size) {
		if(size >= new_size) {
			ERROR("attempted string expansion to non-greater size");
			return;
		}

		char* bigger_data = new char[new_size];
		for(int i = 0; i < length; i++) {
			bigger_data[i] = data[i];
		}
		delete[] data;
		data = bigger_data;
		size = new_size;
	}
	~String() {
		delete[] data;
	}
};

#endif
