#define _CRT_SECURE_NO_WARNINGS
#include "Postfix.h"
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include "VStack.h"
#include <string.h>
#include <stdio.h>

struct _Postfix
{
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	VStack* _operandVStack;

};

Postfix* Postfix_new(int givenMaxNumberOfTokens)
{
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	_this->_operandVStack = VStack_new(givenMaxNumberOfTokens);

	return _this;
}

void Postfix_delete(Postfix* _this)
{
	VStack_delete(_this->_operandVStack);
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
	
	while (_this->_expression[i] >=33 && _this->_expression[i]<=126) {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9')
		{
			operand = (currentToken - '0');
			if (VStack_size(_this->_operandVStack) == _this->_maxNumberOfTokens) return PostfixError_ExpressionTooLong;
			VStack_push(_this->_operandVStack, operand);
		}
		else {
			if (currentToken == '+')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);
					calculated = operand1 + operand2;
					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '-')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);
					calculated = operand1 - operand2;
					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '*')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);
					calculated = operand1 * operand2;
					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '/')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);

					if (operand2 == 0) return PostfixError_DivideByZero;

					calculated = operand1 / operand2;
					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}
			else if (currentToken == '%')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);
					calculated = operand1 % operand2;

					if (operand2 == 0) return PostfixError_DivideByZero;

					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}

			else if (currentToken == '^')
			{
				if (VStack_size(_this->_operandVStack) >= 2)
				{
					operand2 = VStack_pop(_this->_operandVStack);
					operand1 = VStack_pop(_this->_operandVStack);
					
					calculated = 1;

					for (int z = 0; z < operand1; z++)
					{
						calculated *= operand2;
					}

					VStack_push(_this->_operandVStack, calculated);
				}
				else return PostfixError_OperandsTooFew;
			}

			else return PostfixError_UnknownOperator;
		}

		Postfix_showTokenAndVStack(_this, currentToken);
		i++;
	}


	if (VStack_size(_this->_operandVStack) == 1)
		_this->_evaluatedValue = VStack_pop(_this->_operandVStack);

	else if (VStack_size(_this->_operandVStack) > 1)
		return  PostfixError_OperandsTooMany;

	return  PostfixError_None;

}

void Postfix_showTokenAndVStack(Postfix* _this, char currentToken)
{
	printf("\n%c : VStack <Bottom> ", currentToken);

	for (int x = 0; x < VStack_size(_this->_operandVStack); x++)
	{
		if (!OStack_isEmpty(_this->_operandVStack))
			AppView_out_element(VStack_elementAt(_this->_operandVStack, x));
	}

	printf("<Top>");
}


