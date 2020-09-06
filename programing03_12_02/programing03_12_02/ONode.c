#include "ONode.h"
#include "Common.h"

struct _ONode
{
	Element _element;
	ONode* _next;
};

ONode* ONode_new()
{
	ONode* _this = NewObject(ONode);
	return  _this;
}

void ONode_delete(ONode* _this)
{
	free(_this);
}

void  ONode_setElement(ONode* _this, Element newElement)
{
	_this->_element = newElement;
}

Element  ONode_element(ONode* _this)
{
	return  _this->_element;
}

void  ONode_setNext(ONode* _this, ONode* newNext)
{
	_this->_next = newNext;
}

ONode* ONode_next(ONode* _this)
{
	return  _this->_next;
}
