#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include "Postfix.h"
#include <stdio.h>

#pragma warning (disable: 4028)


#define  ErrorMsg_ExpressionTooLong "\n[오류] 수식이 너무 길어 처리가 불가능합니다.\n" 
#define  ErrorMsg_OperandsTooMany "\n[오류] 연산값에 비해 연산자의 수가 적습니다.\n" 
#define  ErrorMsg_OperandsTooFew "\n[오류] 연산값에 비해 연산자의 수가 많습니다.\n" 
#define  ErrorMsg_UndefinedOperator "\n[오류] 수식에 알 수 없는 연산자가 있습니다.\n"
#define  ErrorMsg_DivideByZero "\n[오류] 나눗셈의 분모가 0 입니다.\n"


void AppView_out_startingMessage()
{
    printf("<<< Postfix 수식 계산을 시작합니다 >>>\n");
}

Boolean AppView_in_postfixExpression(char* expression)
{
    printf("\n> Postfix 수식을 입력하시오: ");

    scanf("%s", expression);

    char test = expression[0];
    if ((test >= '0' && test <= '9')) return TRUE;
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

void  AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError)
{
    if (aPostfixError == PostfixError_ExpressionTooLong) printf(ErrorMsg_ExpressionTooLong);
    else if (aPostfixError == PostfixError_OperandsTooMany) printf(ErrorMsg_OperandsTooMany);
    else if (aPostfixError == PostfixError_OperandsTooFew)  printf(ErrorMsg_OperandsTooFew);
    else if (aPostfixError == PostfixError_UnknownOperator)  printf(ErrorMsg_UndefinedOperator);
    else if (aPostfixError == PostfixError_DivideByZero) printf(ErrorMsg_DivideByZero);

}