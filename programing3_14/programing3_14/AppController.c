#include <stdio.h>
#include <time.h>
#pragma warning(disable:6011)

#include "AppController.h"
#include "AppView.h"
#include "ParameterSet.h"
#include "Common.h"
#include "Timer.h"

#define MIN_TEST_SIZE 1000
#define NUMBER_OF_TESTS 5
#define INTERVAL_SIZE 1000

typedef  struct _AppController
{
	ParameterSet* _parameterSet;
	int* _testData;

}AppController;

AppController* AppController_new()
{
	AppController* _this = NewObject(AppController);
	_this->_parameterSet = ParameterSet_new();
	return _this;
}

void AppController_run(AppController* _this)
{
	AppView_out("<사전(Dictionary)의 구현에 따른 실행 성능 차이 알아보기>\n");
	AppController_initPerformanceMeasurement(_this);

	int numberOfTests = ParameterSet_numberOfTests(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);
	int intervalSize = ParameterSet_intervalSize(_this->_parameterSet);

	AppView_out("\n[Unsorted Array]");

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedArrayDictionary* DictionaryForTest = UnsortedArrayDictionary_new(testSize);Dictionary

		double  timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, DictionaryForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedArrayDictionary_removeMax(_this, DictionaryForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayDictionary_min(_this, DictionaryForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForRemoveMax, timeForMin);


		UnsortedArrayDictionary_delete(DictionaryForTest);

		testSize += intervalSize;
	}
	AppView_out();
	testSize = ParameterSet_minTestSize(_this->_parameterSet);

	AppView_out("\n[Sorted Array]");

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedArrayDictionary* DictionaryForTest = UnsortedArrayDictionary_new(testSize); Dictionary

			double  timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, DictionaryForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedArrayDictionary_removeMax(_this, DictionaryForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayDictionary_min(_this, DictionaryForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForRemoveMax, timeForMin);


		UnsortedArrayDictionary_delete(DictionaryForTest);

		testSize += intervalSize;
	}
	AppView_out();
	testSize = ParameterSet_minTestSize(_this->_parameterSet);

	AppView_out("\n[Unsorted Linked List]");

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedArrayDictionary* DictionaryForTest = UnsortedArrayDictionary_new(testSize); Dictionary

			double  timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, DictionaryForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedArrayDictionary_removeMax(_this, DictionaryForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayDictionary_min(_this, DictionaryForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForRemoveMax, timeForMin);


		UnsortedArrayDictionary_delete(DictionaryForTest);

		testSize += intervalSize;
	}
	AppView_out();
	testSize = ParameterSet_minTestSize(_this->_parameterSet);

	AppView_out("\n[Sorted Linked List]");

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedArrayDictionary* DictionaryForTest = UnsortedArrayDictionary_new(testSize); Dictionary

			double  timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, DictionaryForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedArrayDictionary_removeMax(_this, DictionaryForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayDictionary_min(_this, DictionaryForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForRemoveMax, timeForMin);


		UnsortedArrayDictionary_delete(DictionaryForTest);

		testSize += intervalSize;
	}
	AppView_out();
	testSize = ParameterSet_minTestSize(_this->_parameterSet);

	AppView_out("\n[Binary Search Tree]");

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);

	for (int x = 0; x < numberOfTests; x++)
	{
		UnsortedArrayDictionary* DictionaryForTest = UnsortedArrayDictionary_new(testSize); Dictionary

			double  timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, DictionaryForTest, testSize);
		double  timeForRemoveMax = AppController_timeForUnsortedArrayDictionary_removeMax(_this, DictionaryForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayDictionary_min(_this, DictionaryForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForRemoveMax, timeForMin);


		UnsortedArrayDictionary_delete(DictionaryForTest);

		testSize += intervalSize;
	}

	testSize = ParameterSet_minTestSize(_this->_parameterSet);

	AppView_out("< Dictionary의 성능 측정을 종료합니다 >");

}

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForSearch, double aTimeForRemove)
{
	char  results[255];
	sprintf(results, "크기: %4d,  삽입: %6ld, 검색: %7ld, 삭제: %7ld\n", aTestSize, (long)aTimeForAdd, (long)aTimeForSearch, (long)aTimeForRemove);
	AppView_out(results);

}

