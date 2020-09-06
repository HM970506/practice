#ifndef Infix_AppView_h
#define Infix_AppView_h

typedef enum _Boolean Boolean;
typedef int Element;

void AppView_out_startingMessage();
Boolean AppView_in_InfixExpression(char* expression);
void AppView_out_errorInExpression();
void AppView_out_evaluatedValue(int value);
void AppView_out_endingMessage();
void AppView_out_element(int anElement);
void AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError);
void AppViex_out_Infixstart();
void AppView_out_charelement(char anElement);
void AppViex_out_Infixend();
void AppView_out_postfixStart();

#endif
