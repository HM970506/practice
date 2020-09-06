#ifndef Stack_Stack_h
#define Stack_Stack_h

typedef struct _Stack Stack;
typedef enum _Boolean Boolean;
typedef int Element;

typedef struct _Stack {

	int _capacity;
	int _top; 
	Element* _elements;

}Stack;

Stack* Stack_new();
void  Stack_delete(Stack* _this);
Boolean  Stack_isEmpty(Stack* _this);
Boolean Stack_isFull(Stack* _this);
int  Stack_size(Stack* _this);
Boolean  Stack_push(Stack* _this, Element anElement);
Element  Stack_pop(Stack* _this);

Element  Stack_topElement(Stack* _this);
Element  Stack_elementAt(Stack* _this, int anOrder);

#endif