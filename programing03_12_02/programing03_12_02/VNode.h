#ifndef Infix_VNode_h
#define Infix_VNode_h

typedef struct _VNode VNode;
typedef int Element;

VNode* VNode_new();
void VNode_delete(VNode* _this);

void  VNode_setElement(VNode* _this, Element newElement);
Element  VNode_element(VNode* _this);

void  VNode_setNext(VNode* _this, VNode* newNext);
VNode* VNode_next(VNode* _this);

#endif
