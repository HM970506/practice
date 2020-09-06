#ifndef ListTimer_Node_h
#define ListTimer_Node_h

typedef int Element;
typedef struct _Node Node;

struct _Node
{
	Element _element;
	Node* _next;

};



Node* Node_new();
void  Node_delete(Node* _this);
void  Node_setElement(Node* _this, Element newElement);
Element Node_element(Node* _this);
void  Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);

#endif