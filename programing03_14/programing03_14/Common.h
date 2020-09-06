#ifndef Common_h
#define Common_h
#include "stddef.h"
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define Esc 27
#define VALUE_FOR_EMPTY 5
#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <='9'))
#define isAlpha(CHAR) ((('A'<=CHAR)&& (CHAR <='Z')) || (('a'<=CHAR) && (CHAR<='z')))

typedef enum _Boolean {
	FALSE,
	TRUE
}Boolean;

#endif
