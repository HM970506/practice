#ifndef Stack_Common_h
#define Stack_Common_h

#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum _Boolean { FALSE, TRUE }Boolean;

#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <='9'))
#define isAlpha(CHAR) ((('A'<=CHAR)&& (CHAR <='Z')) || (('a'<=CHAR) && (CHAR<='z')))



#endif