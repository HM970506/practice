#ifndef ListTimer_Common_h
#define ListTimer_Common_h

#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define ELEMENT_DOES_NOT_EXIST   -1
#undef FALSE
#undef TRUE

typedef enum _Boolean {
	FALSE,
	TRUE
}Boolean;

#endif