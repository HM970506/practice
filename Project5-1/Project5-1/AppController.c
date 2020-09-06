#include "AppController.h"
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

	AppView_out("<<< 마방진 풀이를 시작합니다>>>\n");
	MagicSquare* magicSquare = MagicSquare_new();
	int inputOrder = AppView_in_order();
	while (inputOrder != END_OF_RUN)
	{
		MagicSquare_setOrder(magicSquare, inputOrder);

		if (MagicSquare_orderIsValid(magicSquare)) {
			MagicSquare_solve(magicSquare);
			AppController_showBoard(_this, magicSquare);
		}
		inputOrder = AppView_in_order();
	}

	AppView_out("\n<<<마방진 풀이를 종료합니다>>>\n");
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
