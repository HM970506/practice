#include "MagicSquare.h"
#include "AppView.h"
#include <stdio.h>

typedef struct {
	int _row;
	int _col;
} CellLocation;

#define EMPTY_CELL -1

CellLocation currentLoc;
CellLocation nextLoc;

Boolean MagicSquare_orderIsValid(MagicSquare* _this)
{
	if (_this->_order < 3) {
		AppView_out("오류:차수가 너무 작습니다. 3 보다 크거나 같아야 합니다.\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "오류: 차수가 너무 큽니다. %d 보다 작거나 같아야 합니다.\n", MAX_ORDER);
		AppView_out(messageBuffer);
		return FALSE;
	}
	else if ((_this->_order % 2) == 0) {
		AppView_out("오류: 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}

	else return TRUE;
}

void MagicSquare_solve(MagicSquare* aMagicSquar)
{
	for (int row = 0; row < aMagicSquare._order; row++)
	{
		for (int col = 0; col < aMagicSquare._order; col++) {
			aBoard[row][col] = EMPTY_CELL; //정해진 칸만큼 -1로 채움
		}
	}
	int cellValue = 1;
	int lastCellValue = aMagicSquare._order * aMagicSquare._order;

	currentLoc._row = 0;
	currentLoc._col = (int)(aMagicSquare._order / 2);
	aBoard[currentLoc._row][currentLoc._col] = cellValue; //가운데가 1

	cellValue = 2;

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		
			nextLoc._row = currentLoc._row - 1;
			if (nextLoc._row < 0) nextLoc._row = aMagicSquare._order - 1; //맵밖
			nextLoc._col = currentLoc._col + 1;
			if (nextLoc._col >= aMagicSquare._order) nextLoc._col = 0; //맵밖

			
				if (aBoard[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
					nextLoc._row = currentLoc._row + 1;
					nextLoc._col = currentLoc._col;
				}

				aBoard[nextLoc._row][nextLoc._col] = cellValue;


				currentLoc._col = nextLoc._col;
				currentLoc._row = nextLoc._row;
	}

}

void MagicSquare_setOrder(MagicSquare* _this, int newOrder)
{
	_this->_order = newOrder;
}
