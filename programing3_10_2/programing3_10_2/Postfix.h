#ifndef Postfix_Postfix_h
#define Postfix_Postfix_h

typedef struct _Stack Stack;
typedef enum _Boolean Boolean;
typedef enum _PostfixError PostfixError;

typedef struct _Postfix
{
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	Stack* _operandStack;

}Postfix;

Postfix* Postfix_new(int givenMaxNumberOfTokens);
void  Postfix_delete(Postfix* _this);
void  Postfix_setExpression(Postfix* _this, char* anExpression);
PostfixError Postfix_evaluate(Postfix* _this);
int  Postfix_evaluatedValue(Postfix* _this);
void Postfix_showTokenAndStack(Postfix* _this, char currentToken);

#endif