#include "AppController.h"
#include "Common.h"
#include "AppView.h"
#include "Queue.h"
#pragma warning(disable:4047)

struct _AppController
{
	Queue* _queue;
	int _inputChars;
	int _ignoredChars;
	int _addedChars;
};

AppController* AppController_new() {

	AppController* _this = NewObject(AppController);
	_this->_queue = Queue_new();
	_this->_inputChars = 0; 
	_this->_ignoredChars = 0; 
	_this->_addedChars = 0;
	return (_this);
}

void AppController_delete(AppController* _this)
{ 
	Queue_delete(_this->_queue);
	free(_this);
}

void AppController_run(AppController* _this) {

	AppView_out_startProgram(); 
	AppController_initCharCounts(_this);

	char inputChar = AppView_in_nextInputChar();
	AppController_countInput(_this); 

	while (inputChar != Esc) {
		if (isAlpha(inputChar))  AppController_add(_this, inputChar); 
		else if (isDigit(inputChar))  AppController_removeN(_this, inputChar); 
		else if (inputChar == '-') AppController_remove1(_this); 
		else if (inputChar == '#') AppController_showSize(_this); 
		else if (inputChar == '/') AppController_showAllFromFront(_this); 
		else if (inputChar == '^') AppController_showFront(_this); 
		else { AppController_ignore(_this); } 

		inputChar = AppView_in_nextInputChar(); 
		if(inputChar!=Esc) AppController_countInput(_this);

	} 
	
	AppController_esc(_this);
	AppView_out_endProgram();
}

void AppController_esc(AppController* _this)
{
	char deleteElement=NULL;

	while(!Queue_isEmpty(_this->_queue))
	{
		deleteElement=Queue_remove(_this->_queue);
		AppView_out_Esc(deleteElement);
	}

	AppView_out_Esc1(_this->_inputChars);
	AppView_out_Esc2((_this->_inputChars)-(_this->_ignoredChars));
	AppView_out_Esc3(_this->_ignoredChars);
	AppView_out_Esc4(_this->_addedChars);

}

void AppController_ignore(AppController* _this)
{
	_this->_ignoredChars++;
	AppView_out_ignore();
}

void AppController_showSize(AppController* _this)
{
	int size = Queue_size(_this->_queue);
	AppView_out_showsize(size);
}

void  AppController_add(AppController* _this, char aChar) {

	if (Queue_add(_this->_queue, aChar))
	{
		AppController_countAdded(_this);
		AppView_out_addedElementInQueue(aChar);
	}
	else AppView_out_queueIsFull(aChar);
}

void AppController_countAdded(AppController* _this)
{
	_this->_addedChars++;
}

void  AppController_remove1(AppController* _this) {

	char   removedChar;
	if (Queue_isEmpty(_this->_queue))
	{
		AppView_out_noElementInQueue();
		_this->_inputChars--;
	}
	else {
		removedChar = Queue_remove(_this->_queue);
		AppView_out_removedElementFromQueue(removedChar);
	}
}

void AppController_removeN(AppController* _this, char aDigit) {
	
	int  numberOfCharsRemoved = aDigit-'0';
	char deleteElement;

	for (int x = 0; x < numberOfCharsRemoved; x++)
	{
		if (!Queue_isEmpty(_this->_queue))
		{
			deleteElement = Queue_elementAt(_this->_queue, 0);
			Queue_remove(_this->_queue);
			AppView_out_removedElementFromQueueN(deleteElement);
		}

		else
		{
			AppView_out_noElementInQueue();
			break;
		}
	}

}

void  AppController_showAllFromFront(AppController* _this) {

	AppView_out_labelstart();
	for (int i = 0; i < Queue_size(_this->_queue); i++)
	{
		AppView_out_elementInQueue(Queue_elementAt(_this->_queue, i));
	}
	AppView_out_labelend();
}

void  AppController_initCharCounts(AppController* _this){
	_this->_inputChars = 0; 
	_this->_ignoredChars = 0; 
	_this->_addedChars = 0; 
}

void  AppController_countInput(AppController* _this){ 
	_this->_inputChars+=1; 
}

void AppController_showFront(AppController* _this)
{
	char front = Queue_frontNode(_this->_queue);
	AppView_showFront(front);

}