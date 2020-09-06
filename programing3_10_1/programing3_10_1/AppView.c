#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include "Postfix.h"
#include <stdio.h>

void AppView_out_startingMessage()
{
    printf("<<< Postfix 수식 계산을 시작합니다 >>>\n");
}

Boolean AppView_in_postfixExpression(AppController* _this)
{
    printf("\n> Postfix 수식을 입력하시오: ");
    scanf("%s", _this->_expression);

    char test = _this->_expression[0];
    if (test>='0' && test<='9') return TRUE;
    else return FALSE;
}

void AppView_out_errorInExpression()
{
    printf(" > 수식에 오류가 있습니다.\n");
}

void AppView_out_evaluatedValue(int value)
{
    printf("\n계산값 : %d\n", value);
}

void AppView_out_endingMessage()
{
    printf("\n<<< Postfix 수식 계산을 종료합니다 >>>");
}

void AppView_out_element(int anElement)
{
    printf("%d ", anElement);
}