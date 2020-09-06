#define _CRT_SECURE_NO_WARNINGS
#include "Postfix.h"
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include "Stack.h"
#include <string.h>
#include <stdio.h>

struct _Postfix
{
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	Stack* _operandStack;

};

Postfix* Postfix_new(int givenMaxNumberOfTokens)
{
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	_this->_operandStack = Stack_new(givenMaxNumberOfTokens);

	return _this;
}

void Postfix_delete(Postfix* _this)
{
	Stack_delete(_this->_operandStack);
	_this->_expression = NULL;
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

PostfixError Postfix_evaluate(Postfix* _this)
{
	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;

	Stack_reset(_this->_operandStack);

	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9')
		{
			operand = (currentToken - '0');
			if (Stack_size(_this->_operandStack)==_this->_maxNumberOfTokens) return PostfixError_ExpressionTooLong;
			Stack_push(_this->_operandStack, operand);
		}
		else {
			if (currentToken == '+')
			{
				if (Stack_size(_this->_operandStack) >= 2)
				{
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '-')
			{
				if (Stack_size(_this->_operandStack) >= 2)
				{
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 - operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '*')
			{
				if (Stack_size(_this->_operandStack) >= 2)
				{
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 * operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '/')
			{
				if (Stack_size(_this->_operandStack) >= 2)
				{
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);

					if (operand2 == 0) return PostfixError_DivideByZero;

					calculated = operand1 / operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '%')
			{
				if (Stack_size(_this->_operandStack) >= 2)
				{
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 % operand2;

					if (operand2 == 0) return PostfixError_DivideByZero;

					Stack_push(_this->_operandStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else return PostfixError_UnknownOperator;
		}

		Postfix_showTokenAndStack(_this, currentToken);
		i++;
	}


	if (Stack_size(_this->_operandStack) == 1)
		_this->_evaluatedValue = Stack_pop(_this->_operandStack);

	else if (Stack_size(_this->_operandStack) > 1)
		return  PostfixError_OperandsTooMany;

	return  PostfixError_None;

}

void Postfix_showTokenAndStack(Postfix* _this, char currentToken)
{
	printf("\n%c : Stack <Bottom> ", currentToken);

	Stack_showLinkedChain(_this->_operandStack);

	printf("<Top>");
}


