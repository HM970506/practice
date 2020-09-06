#define _CRT_SECURE_NO_WARNINGS
#include "Postfix.h"
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include "Stack.h"
#include <string.h>
#include <stdio.h>

Postfix* Postfix_new(int givenMaxNumberOfTokens)
{ 
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens; 
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	_this->_operandStack = Stack_new(givenMaxNumberOfTokens);
	
	return _this;
}

void  Postfix_delete(Postfix* _this) 
{
	Stack_delete(_this->_operandStack); 
	free(_this->_expression);
	free(_this); 

}

void Postfix_setExpression(Postfix* _this, char* anExpression) 
{ 
	strcpy(_this->_expression, anExpression); 
}

int Postfix_evaluatedValue(Postfix* _this) 
{
	return (_this->_evaluatedValue);
}

Boolean Postfix_evaluate(Postfix* _this)
{
	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0; 
	
	Stack_reset(_this->_operandStack);

	while (_this->_expression[i] !='\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9')
		{
			operand = (currentToken - '0');
			Stack_push(_this->_operandStack, operand);
		}
		else {
			if (currentToken == '+')
			{
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);
				calculated = operand1 + operand2;
				Stack_push(_this->_operandStack, calculated);
			}
			else if (currentToken == '-')
			{
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);
				calculated = operand1 - operand2;
				Stack_push(_this->_operandStack, calculated);
			}
			else if (currentToken == '*')
			{
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);
				calculated = operand1 * operand2;
				Stack_push(_this->_operandStack, calculated);
			}
			else if (currentToken == '/') {
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack); calculated = operand1/operand2;
				Stack_push(_this->_operandStack, calculated);
			}
			else if (currentToken == '%')
			{
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);
				calculated = operand1 % operand2;
				Stack_push(_this->_operandStack, calculated);
			}
		}

		Postfix_showTokenAndStack(_this, currentToken); // 여기에 출력이 있는 이유는? 
		i++;
	}
	_this->_evaluatedValue = Stack_pop(_this->_operandStack);
	return TRUE;
}

void Postfix_showTokenAndStack(Postfix* _this, char currentToken)
{
	printf("\n%c : Stack <Bottom> ", currentToken);
	
	int stackElement;

	for (int i = 0; i < Stack_size(_this->_operandStack); i++)
	{
		stackElement = Stack_elementAt(_this->_operandStack, i);
		AppView_out_element(stackElement);
	}

	printf("<Top>");
}


