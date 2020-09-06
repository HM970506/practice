#ifndef Node_h
#define Node_h

typedef struct _Node Node;
typedef char Element;

Node* Node_new();
void Node_delete(Node* _this);
void Node_setElement(Node* _this, Element anElement);
Element  Node_element(Node* _this);

void  Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);
#endif