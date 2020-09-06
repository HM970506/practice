#include "BinaryNode.h"
#include "Common.h"
#include "Key.h"
#include "Object.h"

struct  _BinaryNode 
{
    Key* _key; 
    Object* _object;
    int depth;
    BinaryNode* _left;
    BinaryNode* _right; 
};


BinaryNode* BinaryNode_new()
{
    BinaryNode* _this = NewObject(BinaryNode);
    _this->_key = Key_new();
    _this->_left = NULL;
    _this->_right = NULL;
    _this->_object = Object_new();
    _this->depth = 0;
    return _this;
}

BinaryNode* BinaryNode_newWith(Key* aKey, Object* anObject, BinaryNode* aLeft, BinaryNode* aRight)
{
    BinaryNode* _this = NewObject(BinaryNode);
    _this->_key = aKey;
    _this->_left = aLeft;
    _this->_right = aRight;
    _this->_object = anObject;
    return _this;
}

void BinaryNode_delete(BinaryNode* _this)
{
    Key_delete(_this->_key);
    Object_delete(_this->_object);
    free(_this);
}

void BinaryNode_setKey(BinaryNode* _this, Key* aKey)
{
    _this->_key = aKey;
}

Key* BinaryNode_key(BinaryNode* _this)
{
    return _this->_key;
}

void BinaryNode_setObject(BinaryNode* _this, Object* anObject)
{
    _this->_object = anObject;
}

Object* BinaryNode_object(BinaryNode* _this)
{
    return _this->_object;
}

BinaryNode* BinaryNode_left(BinaryNode* _this)
{
    return _this->_left;
}

void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aleft)
{
    _this->_left = aleft;
}

BinaryNode* BinaryNode_right(BinaryNode* _this)
{
    return _this->_right;
}

void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight)
{
    _this->_right = aRight;
}
