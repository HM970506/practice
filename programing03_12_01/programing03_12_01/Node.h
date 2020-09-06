#ifndef Postfix_Node_h
#define Postfix_Node_h

typedef struct _Node Node;
typedef int Element;

Node* Node_new();
void Node_delete(Node* _this);

void  Node_setElement(Node* _this, Element newElement);
Element  Node_element(Node* _this);

void  Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);

#endif
