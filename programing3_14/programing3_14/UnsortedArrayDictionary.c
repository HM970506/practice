#include "UnsortedArrayDictionary.h"
#include "Timer.h"
#include "Common.h"
#include "AppController.h"
#include "Key.h"
#include "Object.h"
#include "Node.h"
#pragma warning(disable: 6011)

typedef struct _UnsortedArrayDictionary
{
	int _size;
	int _capacity;
	Element* _elements;
}UnsortedArrayDictionary;

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int givenCapacity)
{
	UnsortedArrayDictionary* _this = NewObject(UnsortedArrayDictionary);
	_this->_capacity = givenCapacity;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_size = 0;

	return  _this;

}

void  UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this)
{
	free(_this);
}

Boolean  UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this)
{
	return (_this->_size == _this->_capacity);
}

void UnsortedArrayDictionary_addKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject)
{

}
Boolean UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey)
{

}
Element* UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey)
{

}