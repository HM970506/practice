#ifndef ListTimer_AppControlelr_h
#define ListTimer_AppControlelr_h

typedef struct _AppController
{
	int* _testData;

}AppController;

typedef int Element;
typedef struct _UnsortedLinkedList UnsortedLinkedList;
typedef struct _Timer Timer;

AppController* AppController_new(void);
void  AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void  AppController_generateTestDataByRandomNumbers(AppController* _this);
double  AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double  AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax);
double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize);

#endif
