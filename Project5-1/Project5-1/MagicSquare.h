#ifndef MagicSquare_h
#define MagicSquare_h

#include "Common.h"

Boolean MagicSquare_orderIsValid(MagicSquare* _this);
void MagicSquare_solve(MagicSquare* _this);
void MagicSquare_setOrder(MagicSquare* _this, int anOrder);//°´Ã¼ Â÷¼ö¸¦ int·Î
void MagicSquare_delete(MagicSquare* _this); //°´Ã¼¼Ò¸ê
int MagicSquare_order(MagicSquare* _this);//°´Ã¼ Â÷¼ö·Î ¸®ÅÏ
int MagicSquare_cell(MagicSquare* _this, int aRow, int aCol);
MagicSquare* MagicSquare_new();

#endif
