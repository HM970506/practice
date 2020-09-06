#ifndef Postfix_AppView_h
#define Postfix_AppView_h

typedef enum _Boolean Boolean;
typedef int Element;

void AppView_out_startingMessage();
Boolean AppView_in_postfixExpression(AppController* _this);
void AppView_out_errorInExpression();
void AppView_out_evaluatedValue(int value);
void AppView_out_endingMessage();
void AppView_out_element(int anElement);

#endif
