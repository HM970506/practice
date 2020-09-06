#ifndef Infix_ONode_h
#define Infix_ONode_h

typedef struct _ONode ONode;
typedef int Element;

ONode* ONode_new();
void ONode_delete(ONode* _this);

void  ONode_setElement(ONode* _this, Element newElement);
Element ONode_element(ONode* _this);

void  ONode_setNext(ONode* _this, ONode* newNext);
ONode* ONode_next(ONode* _this);

#endif
