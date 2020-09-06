#include "Key.h"
#include "Common.h"
#pragma warning(disable:4047)

struct  _Key {
    KeyValue _value;
};

int  Key_compareTo(Key* _this, Key* otherKey) {

    if (_this->_value == otherKey->_value) return 0;
    else if (_this->_value < otherKey->_value) return 1;
    else return -1;
}

Key* Key_new(void)
{
    Key* _this = NewObject(Key*);
    return _this;
}

Key* Key_newWith(KeyValue givenValue)
{
    Key* _this = Key_new();
    _this->_value = givenValue;
    return _this;
}

void Key_delete(Key* _this)
{
    free(_this);
}

void Key_setValue(Key* _this, KeyValue newValue)
{
    _this->_value = newValue;
}

KeyValue Key_value(Key* _this)
{
    return _this->_value;
}
