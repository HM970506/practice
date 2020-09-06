#include "AppController.h"
#include "Timer.h"
#include "AppView.h"
#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6262)
#pragma warning(disable:4244)

#define END_OF_RUN -1

struct _AppController {
	MagicSquare* magicSquare;
};

void AppController_showBoard(AppController* _this, MagicSquare* aMagicSquare)
{
	char messageBuffer[255];
	int order = MagicSquare_order(aMagicSquare);
	sprintf(messageBuffer, "Magic Sqare Board: Order %2d\n", order);
	AppView_out(messageBuffer);
	AppView_out("    ");

	for (int col = 0; col < order; col++) {

		sprintf(messageBuffer, "[%2d]", col);
		AppView_out(messageBuffer);

	}
	AppView_out("\n");
	for (int row = 0; row < order; row++)
	{
		sprintf(messageBuffer, "[%2d]", row);
		AppView_out(messageBuffer);

		for (int col = 0; col < order; col++)
		{
			sprintf(messageBuffer, "%5d", MagicSquare_cell(aMagicSquare, row, col));
			AppView_out(messageBuffer);
		}
		AppView_out("\n");
	}
}

void AppController_run(AppController* _this) //main역할
{
	MagicSquare* magicSquare;
	int order, count;
	Timer* timer;
	long executionTime;

	timer = Timer_new();
	AppView_out("<<< 마방진 풀이의 성능 측정을 시작합니다>>>\n");
	AppView_out("하나의 차수에 대해 100회 반복 실행한 시간을 측정합니다.\n");

	for (order = 9; order <= MAX_ORDER; order += 10)
	{
		Timer_start(timer);
		for (count = 0; count < 100; count++) //마방진 실행 100번반복
		{
			magicSquare = MagicSquare_new();
			MagicSquare_setOrder(magicSquare, order);
			MagicSquare_solve(magicSquare);
			MagicSquare_delete(magicSquare);
		}
		Timer_stop(timer);
		executionTime = Timer_duration(timer);
		AppView_out_executionTime(order, executionTime); //print
	}
	Timer_delete(timer);
	AppView_out("\n<<<성능 측정을 마칩니다>>>\n");
	system("pause");
}

void AppController_delete(AppController* _this)	//객체소멸
{
	free(_this);
}

AppController* AppController_new(void)
{
	AppController* _this = NewObject(AppController);
	return _this;
}
