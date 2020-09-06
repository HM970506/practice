#ifndef ListTimer_AppControlelr_h
#define ListTimer_AppControlelr_h

typedef  struct _AppController AppController;
typedef struct _UnsortedArrayList UnsortedArrayList;
typedef struct _SortedArrayList SortedArrayList;
typedef int Element;

AppController* AppController_new(void);
void  AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void AppController_generateTestDataByRandomNumbers(AppController* _this);
double AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, int aTestSize);
double AppController_timeForUnsortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize);
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForRemoveMax, double aTimeForMin);

void AppController_initPerformanceMeasurement(AppController* _this);
double AppController_timeForUnsortedArrayList_min(AppController* _this, UnsortedArrayList* aList, int aTestSize);

double AppController_timeForSortedArrayList_add(AppController* _this, SortedArrayList* aList, int aTestSize);
double AppController_timeForSortedArrayList_removeMax(AppController* _this, SortedArrayList* aList, int aTestSize);
double AppController_timeForSortedArrayList_min(AppController* _this, SortedArrayList* aList, int aTestSize);


#endif