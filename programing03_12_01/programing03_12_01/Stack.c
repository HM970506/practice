#include "Stack.h"
#include "Node.h"
#include "Common.h"
#include "AppView.h"
#include <stdio.h>
#pragma warning(disable: 4047)

struct _Stack {

	int _size;
	Node* _top;

};

Stack* Stack_new(int givenCapacity)
{
	Stack* _this;
	_this = NewObject(Stack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}

void Stack_delete(Stack* _this)
{
	Stack_deleteLinkedChain(_this);
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this)
{
	return  ((_this->_size)== 0);
}

Boolean Stack_isFull(Stack* _this)
{
	return FALSE;
}

Boolean  Stack_push(Stack* _this, Element anElement)
{
	if (Stack_isFull(_this)) return  FALSE;
	
	Node* nodeForPush = Node_new();
	Node_setElement(nodeForPush, anElement);
	Node_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++; 
	return  TRUE;

}

Element Stack_pop(Stack* _this)
{
	if (Stack_isEmpty(_this))  return NULL;

	Node* poppedNode = _this->_top ;
	Element poppedElement = Node_element (poppedNode) ;
	_this->_top = Node_next (poppedNode) ;
	Node_delete (poppedNode) ;
	_this->_size-- ; 
	return  poppedElement ;
}

int Stack_size(Stack* _this)
{
	return  (_this->_size);
}

void Stack_reset(Stack* _this)
{
	_this->_top = -1;
}

void  Stack_deleteLinkedChain(Stack* _this) //비재귀 (메모리절약)
{
	Node* currentNode = _this->_top;
	Node* nodeToBeDeleted = NULL;

	for (int x = 0; x < Stack_size(_this); x++)
	{
		nodeToBeDeleted = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(nodeToBeDeleted);
	}
}

void Stack_showLinkedChain(Stack* _this)
{
	Node* currentNode = _this->_top;
	Node* nowNode = NULL;
	Stack* test = Stack_new(Stack_size(_this));

	for(int x=0; x<Stack_size(_this); x++)
	{
		nowNode = currentNode;
		currentNode = Node_next(currentNode);
		Stack_push(test, Node_element(nowNode));
	}

	for (int x = 0; x < Stack_size(_this); x++)
	{
		AppView_out_element(Stack_pop(test));
	}

	Stack_delete(test);
}