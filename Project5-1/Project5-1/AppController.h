#ifndef MagicSquare_AppController_h
#define MagicSquare_AppController_h

#include "MagicSquare.h"

typedef struct _AppController AppController;

void AppController_showBoard(AppController* _this, MagicSquare* aMagicSqaure);

void AppController_run(AppController* _this);
void AppController_delete(AppController* _this);

#endif