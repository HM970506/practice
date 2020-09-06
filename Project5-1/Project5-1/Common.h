#ifndef MagicSquare_Common_h
#define MagicSquare_Common_h

#define MAX_ORDER 99
#define EMPTY_CELL -1
#include <stdlib.h>
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))

#undef FALSE
#undef TRUE

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;

#endif