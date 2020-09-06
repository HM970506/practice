#include "MagicSquare.h"
#include "AppView.h"
#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(MagicSquare* aMagicSquare)
{
	char messageBuffer[255];

	sprintf_s(messageBuffer, sizeof(messageBuffer), ">Magic Square Board: Order %2d\n", aMagicSquare->_order);
	AppView_out(messageBuffer);
	AppView_out("    ");

	for (int col = 0; col < aMagicSquare._order; col++) {

		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
		AppView_out(messageBuffer);

	}
	AppView_out("\n");
	for (int row = 0; row < aMagicSquare._order; row++)
	{
		printf("[%2d]", row);

		for (int col = 0; col < aMagicSquare._order; col++)
		{
			printf("%4d", aMagicSquare._board[row][col]);
		}
		AppView_out("\n");
	}
}


int main(void)
{
	MagicSquare magicSquare;
	int inputOrder=0;

	AppView_out("<<< 마방진 풀이를 시작합니다>>>\n");
	inputOrder = AppView_in_order();

	while (inputOrder != END_OF_RUN)
	{
		MagicSquare_setOrder(&magicSquare, inputOrder);

		if (MagicSquare_orderIsValid(&magicSquare)) {
			MagicSquare_solve(&magicSquare);
			Main_showBoard(&magicSquare);
		}
		inputOrder = AppView_in_order();
	}

	AppView_out("\n<<<마방진 풀이를 종료합니다>>>\n");

	return 0;
}