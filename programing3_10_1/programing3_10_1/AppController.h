#ifndef Postfix_AppController_h
#define Postfix_AppController_h

#define MAX_NUMBER_OF_TOKENS 200

typedef struct _Postfix Postfix;

typedef struct _AppController
{ 
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;

}AppController;

void AppController_run(AppController* _this);
AppController* AppController_new();
void AppController_delete(AppController* _this);

#endif
