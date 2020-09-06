#include "Queue.h"
#include "Common.h"
#include "Node.h"

struct _Queue {
	int   _size;
	Node* _front ;
	Node* _rear ;
};

Queue* Queue_new() {
	Queue* _this = NewObject(Queue);
	_this->_size = 0;
	_this->_front = NULL;
	_this->_rear = NULL;

	return  _this;
}

void  Queue_delete(Queue* _this) { 
	
	if(!Queue_isEmpty(_this)) Queue_deleteLinkedChain (_this) ; 
	free (_this) ; 
}

Boolean Queue_add(Queue* _this, Element anElement) {

	if (Queue_isFull(_this)) return  FALSE;

	else {
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, NULL);

		if (Queue_isEmpty(_this)) _this->_front = nodeForAdd;
		else Node_setNext(_this->_rear, nodeForAdd);

		_this->_rear = nodeForAdd;
		_this->_size++;
		return TRUE;
	}	
}

Element Queue_remove(Queue* _this) {

	if (Queue_isEmpty(_this)) return VALUE_FOR_EMPTY;
	else { 
		
		Node* removedNode = _this->_front;
	
		if (_this->_size == 1)
		{
			_this->_front = NULL;
			_this->_rear = NULL;
		} 
		else _this->_front = Node_next(_this->_front);

	Element  removedElement = Node_element(removedNode);
	Node_delete(removedNode);
	_this->_size--;
	return  removedElement; 
	}
}

void  Queue_deleteLinkedChain(Queue* _this)
{
	Node* deleteNow = _this->_front;
	Node* deleteNext = Node_next(deleteNow);

	for (int x = 0; x < _this->_size; x++)
	{
		Node_delete(deleteNow);
		deleteNow = deleteNext;
		deleteNext = Node_next(deleteNow);
	}

	_this->_size = 0;

}

Element  Queue_elementAt(Queue* _this, int anOrder)
{
	Node* nowNode=_this->_front;
	Node* nextNode;

	for (int x = 0; x < anOrder; x++)
	{
		nextNode = Node_next(nowNode);
		if (nextNode != NULL) nowNode = nextNode;
		else break;
	}

	return Node_element(nowNode);
}

Boolean Queue_isEmpty(Queue* _this)
{
	if (_this->_front == NULL) return TRUE;
	else return FALSE;
}

Boolean Queue_isFull(Queue* _this)
{
	return FALSE;
}

Element Queue_size(Queue* _this)
{
	return _this->_size;
}

char Queue_frontNode(Queue* _this)
{
	char frontElement = Node_element(_this->_front);
	return frontElement;
}