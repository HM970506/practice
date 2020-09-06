#include "AppView.h"
#include "Timer.h"
#include <stdio.h>
#pragma warning(disable:4996)

void AppView_out(char* aMessage) {

	printf("%s", aMessage);

}

int AppView_in_order()
{
	int input = 0;
	printf("\n?마방진 차수를 입력하시오:");
	scanf_s("%d", &input);
	return input;
}

void AppView_out_executionTime(int anorder, long anExecutionTime)
{
	printf("차수: %2d, 시간: %1d (마이크로 초)\n", anorder, anExecutionTime);
}