#ifndef Postfix_Common_h
#define Postfix_Common_h

#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum _Boolean { FALSE, TRUE }Boolean;

#endif
