#include "String.h"
#include <fstream>

#ifndef FILE_IO
#define FILE_IO
String read(const char* filename);
void write(const char* filename, String* text);
#endif
