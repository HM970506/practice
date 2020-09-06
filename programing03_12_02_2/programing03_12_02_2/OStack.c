#include "OStack.h"
#include "ONode.h"
#include "Common.h"
#include "AppView.h"
#include <stdio.h>
#pragma warning(disable: 4047)

//Infix->Postfix

struct _OStack
{
	int _size;
	ONode* _top;
};


OStack* OStack_new(int givenCapacity)
{
	OStack* _this;
	_this = NewObject(OStack);
	_this->_top = ONode_new();
	_this->_size = 0;
	return _this;
}

void OStack_delete(OStack* _this)
{
	OStack_deleteLinkedChain(_this);
	free(_this);
}

Boolean OStack_isEmpty(OStack* _this)
{
	return  ((_this->_size) == 0);
}

Boolean OStack_isFull(OStack* _this)
{
	return FALSE;
}

Boolean  OStack_push(OStack* _this, char anElement)
{
	if (OStack_isFull(_this)) return  FALSE;

	ONode* ONodeForPush = ONode_new();
	ONode_setElement(ONodeForPush, anElement);
	ONode_setNext(ONodeForPush, _this->_top);
	_this->_top = ONodeForPush;
	_this->_size++;
	return  TRUE;

}

Element OStack_pop(OStack* _this)
{
	if (OStack_isEmpty(_this)) return NULL;

	ONode* poppedONode = _this->_top;
	Element poppedElement = ONode_element(poppedONode);
	_this->_top = ONode_next(poppedONode);
	ONode_delete(poppedONode);
	_this->_size--;
	return  poppedElement;
}

int OStack_size(OStack* _this)
{
	return  (_this->_size);
}

void  OStack_deleteLinkedChain(OStack* _this) //비재귀 (메모리절약)
{
	ONode* currentONode = _this->_top;
	ONode* ONodeToBeDeleted = NULL;

	for (int x = 0; x < OStack_size(_this); x++)
	{
		ONodeToBeDeleted = currentONode;
		currentONode = ONode_next(currentONode);
		ONode_delete(ONodeToBeDeleted);
	}
}

ElementForOStack  OStack_elementAt(OStack* _this, int order)
{
	int  numberOfIteration = (_this->_size) - order - 1;
	ONode* currentNode = _this->_top;

	for (int i = 0; i < numberOfIteration; i++)
	{
		currentNode = ONode_next(currentNode);
	}

	return ONode_element(currentNode);

}


ElementForOStack  OStack_peek(OStack* _this)
{
	if (OStack_isEmpty(_this)) return NULL;
	else
	{
		Element  topElement = ONode_element(_this->_top);
		return  topElement;
	}
}

int OStack_topElement(OStack* _this)
{
	return OStack_peek(_this);
}