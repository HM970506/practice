#include "AppView.h"
#include "Timer.h"
#include "AppController.h"
#pragma warning(disable:6262)
#include <stdio.h>

#define END_OF_RUN -1

int main(void)
{
	AppController* appController = AppController_new();
	AppController_run(appController);
	AppController_delete(appController);
	return 0;
}