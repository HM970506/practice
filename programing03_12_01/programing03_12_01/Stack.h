#ifndef Postfix_Stack_h
#define Postfix_Stack_h

typedef enum _Boolean Boolean;
typedef int Element;
typedef struct _Stack Stack;

Stack* Stack_new(int givenCapacity);
void  Stack_delete(Stack* _this);
Boolean  Stack_isEmpty(Stack* _this);
Boolean Stack_isFull(Stack* _this);
int  Stack_size(Stack* _this);
Boolean  Stack_push(Stack* _this, Element anElement);
Element  Stack_pop(Stack* _this);

void Stack_reset(Stack* _this);
void  Stack_deleteLinkedChain(Stack* _this);
void Stack_showLinkedChain(Stack* _this);

#endif
