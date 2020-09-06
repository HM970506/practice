#include "Common.h"
#include "MagicSquare.h"
#include "AppView.h"
#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER])
{
	char messageBuffer[255];

	sprintf_s(messageBuffer, sizeof(messageBuffer), ">Magic Square Board: Order %d\n", anOrder);
	AppView_out(messageBuffer);
	AppView_out("    ");

	for (int col = 0; col < anOrder; col++) {

		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
		AppView_out(messageBuffer);
		
	}
	AppView_out("\n");
	for (int row = 0; row < anOrder; row++)
	{
		printf("[%2d]", row);
			for (int col = 0; col < anOrder; col++)
			{
				printf("%4d", aBoard[row][col]);
			}
		
		AppView_out("\n");
	}
}


int main(void)
{
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppView_out("<<< 마방진 풀이를 시작합니다>>>\n");
	inputOrder = AppView_in_order();

	while (inputOrder != END_OF_RUN)
	{
		Boolean orderIsValid = MagicSquare_orderIsValid(inputOrder);
		if (orderIsValid) {
			MagicSquare_solve(inputOrder, board);
			Main_showBoard(inputOrder, board);
		}
		inputOrder = AppView_in_order();
	}

	AppView_out("\n<<<마방진 풀이를 종료합니다>>>\n");

	return 0;
}