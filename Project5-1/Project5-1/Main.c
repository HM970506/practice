#include "MagicSquare.h"
#include "AppController.h"
#include "AppView.h"
#include <stdio.h>

int main(void)
{
	AppController* appController=AppController_new();
	AppController_run(appController);
	AppController_delete(appController);
	return 0;
}