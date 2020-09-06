#ifndef Recursion_Common_h
#define Recursion_Common_h

#include <stdlib.h>

#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE, A, B) do{TYPE t=(A);(A)=(B);(B)=t;}while(0)
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))

typedef enum { FALSE, TRUE }Boolean;

typedef struct {
	int _capacity;
	int _size;
	int* _elements;
}Ban;

typedef struct { 
	Ban* _ban;
}AppController;

typedef struct {
	int _numberOfA;
	int _numberOfB;
	int _numberOfC;
	int _numberOfD;
	int _numberOfF;
}GradeCounter;

#endif