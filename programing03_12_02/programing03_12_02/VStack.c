#include "VStack.h"
#include "VNode.h"
#include "Common.h"
#include "AppView.h"
#include <stdio.h>
#pragma warning(disable: 4047)

struct _VStack {

	int _sizeorder;
	int _size;
	char* _elements;
	VNode* _top;
};

VStack* VStack_new(int givenCapacity)
{
	VStack* _this;
	_this = NewObject(VStack);
	_this->_top = VNode_new();
	_this->_size = 0;
	return _this;
}

void VStack_delete(VStack* _this)
{
	VStack_deleteLinkedChain(_this);
	free(_this);
}

Boolean VStack_isEmpty(VStack* _this)
{
	return  ((_this->_size) == 0);
}

Boolean VStack_isFull(VStack* _this)
{
	return FALSE;
}

Boolean  VStack_push(VStack* _this, Element anElement)
{
	if (VStack_isFull(_this)) return  FALSE;

	VNode* VNodeForPush = VNode_new();
	VNode_setElement(VNodeForPush, anElement);
	VNode_setNext(VNodeForPush, _this->_top);
	_this->_top = VNodeForPush;
	_this->_size++; return  TRUE;

}

Element VStack_pop(VStack* _this)
{
	if (VStack_isEmpty(_this))  return NULL;

	VNode* poppedVNode = _this->_top;
	Element poppedElement = VNode_element(poppedVNode);
	_this->_top = VNode_next(poppedVNode);
	VNode_delete(poppedVNode);
	_this->_size--;
	return  poppedElement;
}

int VStack_size(VStack* _this)
{
	return  (_this->_size);
}

void  VStack_deleteLinkedChain(VStack* _this) //비재귀 (메모리절약)
{
	VNode* currentVNode = _this->_top;
	VNode* VNodeToBeDeleted = NULL;

	for (int x = 0; x < VStack_size(_this); x++)
	{
		VNodeToBeDeleted = currentVNode;
		currentVNode = VNode_next(currentVNode);
		VNode_delete(VNodeToBeDeleted);
	}
}

void VStack_showLinkedChain(VStack* _this)
{
	VNode* currentVNode = _this->_top;
	VNode* nowVNode = NULL;
	VStack* test = VStack_new(VStack_size(_this));

	for (int x = 0; x < VStack_size(_this); x++)
	{
		nowVNode = currentVNode;
		currentVNode = VNode_next(currentVNode);
		VStack_push(test, VNode_element(nowVNode));
	}

	for (int x = 0; x < VStack_size(_this); x++)
	{
		AppView_out_element(VStack_pop(test));
	}

	VStack_delete(test);
}

ElementForVStack VStack_elementAt(VStack* _this, int order)
{
	int  numberOfIteration = _this->_size - order - 1;
	VNode* currentNode = _this->_top;

	for (int i = 0; i < numberOfIteration; i++)
	{
		currentNode = VNode_next(currentNode);
	}

	return VNode_element(currentNode);
}


ElementForVStack  VStack_peek(VStack* _this)
{
	if (VStack_isEmpty(_this)) return NULL;
	else
	{
		Element  topElement = VNode_element(_this->_top);
		return  topElement;
	}
}