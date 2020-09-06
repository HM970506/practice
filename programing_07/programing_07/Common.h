#ifndef List_Common_h
#define List_Common_h

#include <stdlib.h>
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE, A, B) {TYPE t=A; A=B; B=t;}
#define MAX_STUDENT_ID_LENGTH 9

typedef enum { FALSE, TRUE }Boolean;



#endif