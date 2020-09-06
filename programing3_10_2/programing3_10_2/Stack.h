#ifndef Postfix_Stack_h
#define Postfix_Stack_h

typedef enum _Boolean Boolean;
typedef int Element;

typedef struct _Stack {

	int _capacity;
	int _top;
	Element* _elements;

}Stack;

Stack* Stack_new(int givenCapacity);
void  Stack_delete(Stack* _this);
Boolean  Stack_isEmpty(Stack* _this);
Boolean Stack_isFull(Stack* _this);
int  Stack_size(Stack* _this);
Boolean  Stack_push(Stack* _this, Element anElement);
Element  Stack_pop(Stack* _this);

char Stack_elementAt(Stack* _this, int anOrder);
void Stack_reset(Stack* _this);

#endif
