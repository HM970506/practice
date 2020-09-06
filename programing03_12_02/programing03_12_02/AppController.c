#include "AppController.h"
#include "Common.h"
#include "Postfix.h"
#include "Infix.h"
#include "AppView.h"

struct _AppController
{
	char _expression[200];
	Postfix* _postfix;
	Infix* _infix;
};

AppController* AppContorller_new()
{
	AppController* _this = NewObject(AppController);

	return _this;
}

void AppController_run(AppController* _this)
{
	Boolean expressionIsAvailable;
	PostfixError evaluationError;

	AppView_out_startingMessage();
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
	_this->_infix = Infix_new(MAX_NUMBER_OF_TOKENS);

	expressionIsAvailable = AppView_in_InfixExpression(_this->_expression);


	while (expressionIsAvailable)
	{
		Infix_setExpression(_this->_infix, _this->_expression);

		if ( !((_this->_expression[0]>='0' && _this->_expression[0] <='9') || (_this->_expression[0] =='('))) break;

		AppViex_out_Infixstart();
		if (Infix_toPostfix(_this->_infix))
		{
			Postfix_setExpression(_this->_postfix, Infix_postfix(_this->_infix));

			AppViex_out_Infixend();
			Infix_showPostfix(_this->_infix);
			AppView_out_postfixStart();

			evaluationError = Postfix_evaluate(_this->_postfix);

			if (evaluationError == PostfixError_None)
					AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
			else AppView_out_postfixEvaluationErrorMessage(evaluationError);
			
			Infix_delete(_this->_infix);
			Postfix_delete(_this->_postfix);

			_this->_infix = Infix_new(MAX_NUMBER_OF_TOKENS);
			_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
			expressionIsAvailable = AppView_in_InfixExpression(_this->_expression);
		}
	}


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
