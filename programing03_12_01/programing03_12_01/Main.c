#include "AppController.h"

void main()
{
	AppController* appcontroller = AppController_new();
	AppController_run(appcontroller);
	AppController_delete(appcontroller);
}