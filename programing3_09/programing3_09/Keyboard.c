#include <conio.h>
#include <stdio.h>

char getCharDirectlyFromKeyboard()
{
	char  charFromKeyboard;
	charFromKeyboard = _getch();
	printf("%c", charFromKeyboard);
	return  charFromKeyboard;
}
