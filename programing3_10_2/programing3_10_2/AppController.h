#ifndef Postfix_AppController_h
#define Postfix_AppController_h

#define MAX_NUMBER_OF_TOKENS 5

typedef struct _Postfix Postfix;

typedef struct _AppController
{
	char _expression[200];
	Postfix* _postfix;

}AppController;

void AppController_run(AppController* _this);
AppController* AppController_new();
void AppController_delete(AppController* _this);

#endif
