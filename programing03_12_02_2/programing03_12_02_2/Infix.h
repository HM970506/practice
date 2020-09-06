#ifndef Infix_Infix_h
#define Infix_Infix_h

typedef enum _Boolean Boolean;
typedef struct _Infix Infix;

Infix* Infix_new(int givenMaxNumberOfTokens);
void  Infix_delete(Infix* _this);
void Infix_setExpression(Infix* _this, char* newExpression);
Boolean  Infix_toPostfix(Infix* _this);
char* Infix_postfix(Infix* _this);
int  Infix_inComingPrecedence(char aToken);
int  Infix_inStackPrecedence(char aToken);
void Infix_showTokenAndOStack(Infix* _this, char currentToken);
void Infix_showPostfix(Infix* _this);

#endif
