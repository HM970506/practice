#include "VNode.h"
#include "Common.h"

struct _VNode
{
	Element _element;
	VNode* _next;
};

VNode* VNode_new()
{
	VNode* _this = NewObject(VNode);
	return  _this;
}

void VNode_delete(VNode* _this)
{
	free(_this);
}

void  VNode_setElement(VNode* _this, Element newElement)
{
	_this->_element = newElement;
}

Element VNode_element(VNode* _this)
{
	return  _this->_element;
}

void  VNode_setNext(VNode* _this, VNode* newNext)
{
	_this->_next = newNext;
}

VNode* VNode_next(VNode* _this)
{
	return  _this->_next;
}
