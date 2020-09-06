#ifndef MagicSquare_AppView_h
#define MagicSquare_AppView_h

#include "Common.h"

typedef struct _AppController AppController;

void AppView_out(char* aMessage);
AppController* AppController_new();
int AppView_in_order(void);

#endif