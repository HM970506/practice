#ifndef AppController_h
#define AppController_h

typedef struct _AppController AppController;

AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);
void  AppController_add(AppController* _this, char aChar);
void  AppController_remove1(AppController* _this);
void  AppController_removeN(AppController* _this, char aDigit);
void  AppController_showAllFromFront(AppController* _this);
void  AppController_initCharCounts(AppController* _this);
void  AppController_countInput(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showFront(AppController* _this);
void AppController_ignore(AppController* _this);
void AppController_esc(AppController* _this);
void AppController_countAdded(AppController* _this);


#endif
