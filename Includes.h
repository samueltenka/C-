#ifndef INCLUDES
#define INCLUDES

#define NULL 0

#include <iostream>
	// I like C's printf,
	// but also C++'s cin.s
#define ERROR(X) do {printf("ERROR: "); printf(X); printf("\n"); \
						PAUSE;} while(0)
#define PAUSE do {char pause_l; std::cin >> pause_l;} while(0)

#define STATUS(func_name) printf("STATUS: %s\n", func_name)


#endif INCLUDES
