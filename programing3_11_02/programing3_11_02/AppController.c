#define _CRT_SECURE_NO_WARNINGS
#include "AppController.h"
#include "AppView.h"
#include "Timer.h"
#include "Common.h"
#include "Messages.h"
#include "SortedLinkedList.h"
#include "UnsortedlinkedList.h"
#include "Node.h"
#include <stdio.h>
#include <time.h>

#define MIN_TEST_SIZE 1000
#define NUMBER_OF_TESTS 5
#define INTERVAL_SIZE 1000
#pragma warning(disable: 4087)

AppController* AppController_new()
{
	AppController* _this = NewObject(AppController);
	return _this;
}

void  AppController_delete(AppController* _this)
{
	free(_this);
}

void AppController_run(AppController* _this)
{
	AppView_out(MSG_StartPerformanceMeasuring);
	int numberOfTests = NUMBER_OF_TESTS;
	int intervalSize = INTERVAL_SIZE;
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);

	_this->_testData = NewVector(int, maxTestSize);

	AppController_generateTestDataByRandomNumbers(_this);
	AppView_out(MSG_TitleForUnsortedLinkdeyList);


	int testSize = MIN_TEST_SIZE;

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedLinkedList* listForTest = UnsortedLinkedList_new(testSize);

		double  timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, listForTest, testSize);
		double  timeForMin = AppController_timeForUnsortedLinkedList_min(_this, listForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		UnsortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}
	AppView_out(MSG_TitleForSortedLinkdeList);
	testSize = MIN_TEST_SIZE;

	for (int x = 0; x < numberOfTests; x++)
	{
		SortedLinkedList* listForTest = SortedLinkedList_new(maxTestSize);
		double  timeForAdd = AppController_timeForSortedLinkedList_add(_this, listForTest, testSize);
		double  timeForMin = AppController_timeForSortedLinkedList_min(_this, listForTest, testSize);
		double  timeForRemoveMax = AppController_timeForSortedLinkedList_removeMax(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		SortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}
	AppView_out(MSG_EndPerformanceMeasuring);

}

void  AppController_generateTestDataByRandomNumbers(AppController* _this)
{
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	srand((unsigned)time(NULL));

	for (int y = 0; y < maxTestSize; y++)
	{
		_this->_testData[y] = rand();
	}
}

double  AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double  duration = 0;

	for (int x = 0; x < aTestSize; x++)
	{
		Timer_start(timer);
		if (!SortedLinkedList_isFull(aList)) SortedLinkedList_add(aList, _this->_testData[x]);
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}

	Timer_delete(timer);
	return  duration;

}


double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double  duration = 0;

	for (int x = 0; x < aTestSize; x++)
	{
		Timer_start(timer);
		if (!UnsortedLinkedList_isFull(aList)) UnsortedLinkedList_add(aList, _this->_testData[x]);
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}

	Timer_delete(timer);
	return  duration;

}

double  AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Element max;
	double  duration = 0;
	Timer* timer = Timer_new();

	for (int x = 0; x < aTestSize; x++)
	{
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList)) max = SortedLinkedList_removeMax(aList);
		Timer_stop(timer); duration += Timer_duration(timer);
	}

	Timer_delete(timer);
	return  duration;

}

double  AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Element max;
	double  duration = 0;
	Timer* timer = Timer_new();

	for (int x = 0; x < aTestSize; x++)
	{
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) max = UnsortedLinkedList_removeMax(aList);
		Timer_stop(timer); duration += Timer_duration(timer);
	}

	Timer_delete(timer);
	return  duration;

}

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax)
{
	char  results[255];
	sprintf(results, "크기: %4d,  삽입: %6ld, 최소값얻기: %7ld, 최대값삭제: %7ld\n", aTestSize, (long)aTimeForAdd, (long)aTimeForMin, (long)aTimeForRemoveMax);
	AppView_out(results);

}

double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Element min;
	double duration = 0;
	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++)
	{
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList))  min = UnsortedLinkedList_min(aList);
		Timer_stop(timer); duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return  duration;
}

double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Element min;
	double duration = 0;
	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++)
	{
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList))  min = SortedLinkedList_min(aList);
		Timer_stop(timer); duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return  duration;
}
