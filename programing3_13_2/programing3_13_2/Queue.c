#include "Queue.h"
#include "Common.h"
#pragma warning(disable:4047)

struct _Queue {
	char* _elements[VALUE_FOR_EMPTY];
	int _maxLength;
	int _front;
	int _rear;
};

Queue* Queue_new(int givenCapacity) {

	Queue* _this = NewObject(Queue);
	_this->_maxLength = givenCapacity;
	_this->_front = 0;
	_this->_rear = 0; 

	return _this;
}


void  Queue_delete(Queue* _this) {
	free(_this);
}

Boolean Queue_add(Queue* _this, Element anElement) {

	if (Queue_isFull(_this)) return FALSE;
	else { 
		_this->_rear = Queue_nextRear(_this);
		_this->_elements[_this->_rear] = anElement ; 
		return  TRUE ; 
	}

}

Element Queue_remove(Queue* _this) {

	Element removedElement; 

	if (!Queue_isEmpty(_this)) {

		_this->_front = Queue_nextFront(_this);
		removedElement = _this->_elements[_this->_front];
		_this->_elements[_this->_front] = "";
		return removedElement;
	}

	else return "";

}

Element  Queue_elementAt(Queue* _this, int anOrder)
{
	int index = Queue_nextFront(_this) + anOrder;
	if (index == _this->_maxLength) index %= _this->_maxLength;

	char element=_this->_elements[index];

	return element;
}

Boolean Queue_isEmpty(Queue* _this)
{
	return  (_this->_front == _this->_rear);
}

Boolean Queue_isFull(Queue* _this)
{
	int  nextRear = Queue_nextRear(_this);
	return  (nextRear == _this->_front);

}

Element Queue_size(Queue* _this)
{
	int size = Queue_nextFront(_this) - _this->_rear;
	if (size < 0) size = (-size);

	return size+1;
}

char Queue_frontNode(Queue* _this)
{
	char frontElement = _this->_elements[Queue_nextFront(_this)];
	return frontElement;
}

int Queue_nextRear(Queue* _this)
{
	int next = _this->_rear +1;
	if (next >= _this->_maxLength) next %= _this->_maxLength;

	return next;
}

int Queue_nextFront(Queue* _this)
{
	int next = _this->_front +1;
	if (next >= _this->_maxLength) next %= _this->_maxLength;

	return next;
}