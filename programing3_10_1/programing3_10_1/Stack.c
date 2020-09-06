#include "Stack.h"
#include "Common.h"
#define DEFAULT_STACK_CAPACITY 1000

Stack* Stack_new()
{
	Stack* _this;
	_this = NewObject(Stack);
	_this->_capacity = DEFAULT_STACK_CAPACITY;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_top = -1;
	return _this;
}

void Stack_delete(Stack* _this)
{
	free(_this->_elements);
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this)
{
	return  ((_this->_top) < 0);
}

Boolean Stack_isFull(Stack* _this)
{
	return  ((_this->_top) == (_this->_capacity - 1));
}

Boolean  Stack_push(Stack* _this, Element anElement)
{
	if (!Stack_isFull(_this))
	{
		_this->_top++;
		_this->_elements[_this->_top] = anElement;
		return  TRUE;
	}
	else return  FALSE;

}

Element Stack_pop(Stack* _this)
{
	Element  poppedElement = _this->_elements[_this->_top];
	_this->_top--;
	return  poppedElement;
}

int Stack_size(Stack* _this)
{
	return  (_this->_top + 1);
}

char Stack_elementAt(Stack* _this, int anOrder)
{
	return (_this->_elements[anOrder]);
}

void Stack_reset(Stack* _this)
{ 
	_this->_top = -1; 
}


