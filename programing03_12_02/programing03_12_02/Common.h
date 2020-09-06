#ifndef Infix_Common_h
#define Infix_Common_h

#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <='9'))
#define isAlpha(CHAR) ((('A'<=CHAR)&& (CHAR <='Z')) || (('a'<=CHAR) && (CHAR<='z')))

typedef enum _Boolean { FALSE, TRUE }Boolean;

typedef enum  _PostfixError
{
    PostfixError_None,
    PostfixError_ExpressionTooLong,
    PostfixError_OperandsTooMany,
    PostfixError_OperandsTooFew,
    PostfixError_UnknownOperator,
    PostfixError_DivideByZero
} PostfixError;


#endif