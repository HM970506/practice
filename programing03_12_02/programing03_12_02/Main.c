#include "AppController.h"

void main()
{
	AppController* appcontroller;
	appcontroller = AppController_new();
	AppController_run(appcontroller);
	AppController_delete(appcontroller);
}