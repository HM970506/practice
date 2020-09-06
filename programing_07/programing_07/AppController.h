#ifndef List_AppController_h
#define List_AppController_h

#undef Ban
#include "Common.h"

typedef struct _AppController AppController;
typedef struct _Ban Ban;

AppController* AppController_new();
Boolean AppController_inputAndStoreStudents(AppController* _this);
void  AppController_showStudentsSortedByScore(AppController* _this);
Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore);


void AppController_run(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_delete(AppController* _this);

#endif