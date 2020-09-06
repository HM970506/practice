#include "Object.h"
#include "Common.h"

struct _Object {
	int _objectValue;
};

Object* Object_new()
{
	Object* _this = NewObject(Object);
	return _this;
}
void Object_delete(Object* _this)
{
	free(_this);
}

Object* Object_newWith(ObjectValue givenValue)
{
	Object* _this = NewObject(Object);
	_this->_objectValue = givenValue;
	return _this;
}
void Object_setValue(Object* _this, ObjectValue newValue)
{
	_this->_objectValue = newValue;
}

ObjectValue Object_value(Object* _this)
{
	return _this->_objectValue;
}