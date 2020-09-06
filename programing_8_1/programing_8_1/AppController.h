#ifndef ListTimer_AppControlelr_h
#define ListTimer_AppControlelr_h

typedef struct _AppController
{
	int* _testData;

}AppController;

typedef int Element;
typedef struct _UnsortedArrayList UnsortedArrayList;
typedef struct _Timer Timer;

AppController* AppController_new(void);
void  AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void  AppController_generateTestDataByRandomNumbers(AppController* _this);
double  AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, int aTestSize);
double  AppController_timeForUnsortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize);
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForRemoveMax);

#endif