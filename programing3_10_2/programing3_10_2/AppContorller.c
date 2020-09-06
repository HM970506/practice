#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "AppController.h"
#include "Postfix.h"
#include "AppView.h"
#include <stdio.h>
#include "Stack.h"
#pragma warning(disable: 4133)

void AppController_run(AppController* _this)
{
	Boolean expressionIsAvailable;
	PostfixError evaluationError;

	AppView_out_startingMessage();
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); //새로운 postfix 생성

	expressionIsAvailable = AppView_in_postfixExpression(_this->_expression); //_this->_expression에 식 입력

	while (expressionIsAvailable)
	{
		Postfix_setExpression(_this->_postfix, _this->_expression);
		evaluationError = Postfix_evaluate(_this->_postfix);

		if (evaluationError == PostfixError_None)
			AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		else AppView_out_postfixEvaluationErrorMessage(evaluationError);

		expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
	}

	Postfix_delete(_this->_postfix);
	AppView_out_endingMessage();

}

AppController* AppController_new()
{
	AppController* _this;
	_this = NewObject(AppController);
	return _this;

}

void AppController_delete(AppController* _this)
{
	free(_this);

}
