#include "AppView.h"
#include "Common.h"
#include <conio.h>
#include <stdio.h>

char getCharDirectlyFromKeyboard()
{
	char  charFromKeyboard;
	charFromKeyboard = _getch();
	if (charFromKeyboard == Esc) printf("Esc\n");
	else printf("%c\n", charFromKeyboard);
	return  charFromKeyboard;
}

void AppView_out_startProgram()
{
	printf("<<< Queue 활용 프로그램을 시작합니다 >>>\n");
}

char AppView_in_nextInputChar()
{
	printf("\n>문자를 입력하시오:");
	char input = getCharDirectlyFromKeyboard();
	return input;
}

void AppView_out_queueIsFull(char aChar) {
	printf("[Full]  큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다. \n", aChar);
}

void AppView_out_noElementInQueue() {
	printf("[Empty] 큐에 삭제할 원소가 없습니다. \n");
}

void AppView_out_removedElementFromQueue(char removedChar)
{
	printf("[Remove1] 삭제된 원소는 \'%c\' 입니다. \n", removedChar);
}

void AppView_out_removedElementFromQueueN(char removedChar)
{
	printf("[RemoveN] 삭제된 원소는 \'%c\' 입니다. \n", removedChar);
}

void AppView_out_addedElementInQueue(char aChar)
{
	printf("[Add] 삽입된 원소는 '%c' 입니다.\n", aChar);
}

void AppView_out_ignore()
{
	printf("[ignore] 의미 없는 문자가 입력되었습니다.\n");
}

void AppView_out_showsize(int input)
{
	printf("[Size] 큐에는 현재 %d 개의 원소가 있습니다.\n", input);
}


void AppView_out_labelstart()
{
	printf("<Front> ");
}

void AppView_out_labelend()
{
	printf("<Rear>\n");
}

void AppView_showFront(char front)
{
	printf("[Front] Front 원소는 '%c'입니다.\n", front);
}

void AppView_out_endProgram()
{
	printf("\n<<< Queue 활용 프로그램을 종료합니다 >>>");
}

void AppView_out_Esc(char deleteElement)
{
	printf("[Esc] 삭제된 원소는 '%c' 입니다.\n", deleteElement);
}

void AppView_out_Esc1(int input)
{
	printf("\n.....입력된 문자는 모두 %d 개입니다.\n", input);
}

void AppView_out_Esc2(int input)
{
	printf(".....정상 처리된 문자는 모두 %d 개입니다\n", input);
}

void AppView_out_Esc3(int input)
{
	printf(".....무시된 문자는 %d 개입니다.\n", input);
}

void AppView_out_Esc4(int input)
{
	printf(".....삽입된 문자는 %d 개입니다.\n", input);
}

void AppView_out_elementInQueue(char input)
{
	printf("%c ", input);
}