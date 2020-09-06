#include "AppView.h"
#include "AppController.h"
#include "Key.h"
#include "Object.h"
#include "Common.h"
#include <stdio.h>
#include <conio.h>
#pragma warning(disable:4477)


void AppView_out_start()
{
	printf("<<<사전 활용 프로그램을 시작합니다>>>\n");
}
void AppView_out(char* aString)
{
	printf("%s", aString);
}

void AppView_out_space()
{
	printf("  ");
}

void AppView_out_key(Key* aKey)
{
	printf("%c\n", Key_value(aKey));
}

int AppView_in()
{
    printf("\n>문자를 입력하시오:");

	char  charFromKeyboard;
	charFromKeyboard = _getch();

	if (charFromKeyboard == Esc) printf("Esc\n");
	else printf("%c\n", charFromKeyboard);

	return charFromKeyboard;
}

void AppView_keydelete(Key* aKey, Object* anObject)
{
	printf("[삭제] <%c, %d>이 성공적으로 삭제되었습니다.\n", Key_value(aKey), Object_value(anObject));
}

void AppView_out_showsize(int input)
{
	printf("[Size] 사전에는 현재 %d 개의 키-객체 쌍이 있습니다.\n", input);
}

void AppView_out_add(Key* aKey, Object* anObject)
{
	printf("[ADD] 삽입된 키-객체 쌍은 <'%c', %d>입니다.\n", Key_value(aKey), Object_value(anObject));
}

void AppView_out_search(Key* aKey, Object* anObject)
{
	printf("[검색] <'%c', %d> 쌍이 사전에 존재합니다.\n", Key_value(aKey), Object_value(anObject));
}


void AppView_out_replace(int inputChar)
{
	printf("[Replace] key <'%c'>의 object를 <%d>로 대체합니다.\n", inputChar, inputChar);
}