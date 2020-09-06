#define _CRT_SECURE_NO_WARNINGS
#include "Infix.h"
#include "Common.h"
#include "OStack.h"
#include "AppController.h"
#include "AppView.h"
#include <string.h>
#include <stdio.h>

struct _Infix
{
	char* _infixExpression;
	char* _postfixExpression;
	OStack* _operatorStack;
};

Infix* Infix_new(int givenMaxNumberOfTokens)
{
	Infix* _this = NewObject(Infix);
	_this->_infixExpression = NewVector(char, givenMaxNumberOfTokens);
	_this->_postfixExpression = NewVector(char, givenMaxNumberOfTokens);

	return _this;
}

Boolean Infix_toPostfix(Infix* _this)
{
	int i = 0;
	int p = 0;
	char currentToken = 0, poppedToken = 0;
	int  infixSize = strlen(_this->_infixExpression);
	_this->_operatorStack = OStack_new(infixSize);

	while (i < infixSize)
	{
		currentToken = _this->_infixExpression[i++];
		if (isDigit(currentToken))  //숫자면 postfix에 넣는다
			_this->_postfixExpression[p++] = currentToken;

		else
		{
			if (currentToken == ')')
			{
				if (OStack_isEmpty(_this->_operatorStack))  return FALSE;
				else
				{
					poppedToken = OStack_pop(_this->_operatorStack);

					while (poppedToken != '(')
					{
						_this->_postfixExpression[p++] = poppedToken;
						if (OStack_isEmpty(_this->_operatorStack)) return FALSE;
						else poppedToken = OStack_pop(_this->_operatorStack);
					}
				}
				Infix_showTokenAndOStack(_this, currentToken);
			}
			else
			{
				int inComingPrecedence = Infix_inComingPrecedence(currentToken); //부호면 해당우선순위를 가진다

				while (!OStack_isEmpty(_this->_operatorStack)
					&& Infix_inStackPrecedence(OStack_topElement(_this->_operatorStack)) >= inComingPrecedence)
				{
					poppedToken = OStack_pop(_this->_operatorStack);
					_this->_postfixExpression[p++] = poppedToken;
				}
			}

			if (currentToken != ')') OStack_push(_this->_operatorStack, currentToken);
		}

		if (currentToken != ')') Infix_showTokenAndOStack(_this, currentToken);

	}


	while (!OStack_isEmpty(_this->_operatorStack))
	{
		poppedToken = OStack_pop(_this->_operatorStack);
		_this->_postfixExpression[p++] = poppedToken;
	}

	return  TRUE;
}

int  Infix_inComingPrecedence(char aToken)
{
	if (aToken == '(') return 20;
	else if (aToken == ')')return 19;
	else if (aToken == '^') return 17;
	else if (aToken == '*') return  13;
	else if (aToken == '/') return 13;
	else if (aToken == '%')  return  13;
	else if (aToken == '+')  return 12;
	else if (aToken == '-')  return 12;
	else if (aToken == '$')  return  0;
	else return  -1;
}

int  Infix_inStackPrecedence(char aToken)
{
	if (aToken == '^') return 16;
	else if (aToken == '*')  return 13;
	else if (aToken == '/')  return 13;
	else if (aToken == '%')  return 13;
	else if (aToken == '+')  return 12;
	else if (aToken == '-') return 12;
	else if (aToken == '$') return 0;
	else  return -1;
}

void  Infix_delete(Infix* _this)
{
	OStack_delete(_this->_operatorStack);
	_this->_infixExpression = NULL;
	_this->_postfixExpression = NULL;
	free(_this);
}

void Infix_setExpression(Infix* _this, char* newExpression)
{
	strcpy(_this->_infixExpression, newExpression);
}

char* Infix_postfix(Infix* _this)
{
	int size = MAX_NUMBER_OF_TOKENS;
	char* test = NewVector(char, size);

	for (int x = 0; x < size; x++)
	{
		test[x] = _this->_postfixExpression[x];
	}
	return _this->_postfixExpression;
}

void Infix_showTokenAndOStack(Infix* _this, char currentToken)
{
	printf("\n%c : OStack <Bottom> ", currentToken);

	for (int x = 0; x < OStack_size(_this->_operatorStack); x++)
	{
		if (!OStack_isEmpty(_this->_operatorStack))
			AppView_out_charelement(OStack_elementAt(_this->_operatorStack, x));
	}

	printf("<Top>");
}

void Infix_showPostfix(Infix* _this)
{
	int x = 0;
	while (x < sizeof(_this->_postfixExpression))
	{
		if (_this->_postfixExpression[x] >= 33 && _this->_postfixExpression[x] <= 126)
		{
			printf("%c ", _this->_postfixExpression[x]);
			x++;
		}
		else break;
	}
}