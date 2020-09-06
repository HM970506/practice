#include <conio.h>
#include "Keyboard.h"

char getcharDirectlyFromKeyboard()
{
	char charFromKeyboard = _getch();

	return charFromKeyboard;
}