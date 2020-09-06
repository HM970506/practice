#ifndef Infix_AppController_h
#define Infix_AppController_h

#define MAX_NUMBER_OF_TOKENS 5

typedef struct _AppController AppController;

void AppController_run(AppController* _this);
AppController* AppController_new();
void AppController_delete(AppController* _this);

#endif