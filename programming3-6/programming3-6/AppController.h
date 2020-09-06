#ifndef Recursion_AppController_h
#define Recursion_AppController_h

#undef Ban
#include "Ban.h"
#include "Common.h"

#define MAX_NUMBER_OF_STUDENTS 100

AppController* AppController_new();
void AppController_run(AppController* _this);
Boolean AppController_inputAndStoreStudents(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_showStudentsSortedByScore(AppController* _this);
void AppController_delete(AppController* _this);

#endif