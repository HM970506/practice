#include "Node.h"
#include "Common.h"
#include "Key.h"
#include "Object.h"

struct _Node
{
	Key* _key;
	Object* _object;
	Node* _next;
};


Node* Node_new()
{
	Node* _this = NewObject(Node);
	return  _this;
}

void Node_delete(Node* _this)
{
	free(_this);
}

void  Node_setElement(Node* _this, Element newElement)
{
	_this->_element = newElement;
}

Element  Node_element(Node* _this)
{
	return  _this->_element;
}

void  Node_setNext(Node* _this, Node* newNext)
{
	_this->_next = newNext;
}

Node* Node_next(Node* _this)
{
	return  _this->_next;
}