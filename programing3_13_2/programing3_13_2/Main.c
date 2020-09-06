#include "AppController.h"

int main()
{
	AppController* appcontroller = AppController_new();
	AppController_run(appcontroller);
	AppController_delete(appcontroller);

	return 0;
}