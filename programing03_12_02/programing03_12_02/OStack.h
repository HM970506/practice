#ifndef Infix_OStack_h
#define Infix_OStack_h

typedef  char  ElementForOStack;
typedef int Element;
typedef struct _OStack OStack;
typedef enum _Boolean Boolean;

ElementForOStack  OStack_elementAt(OStack* _this, int order);
ElementForOStack  OStack_peek(OStack* _this);

OStack* OStack_new(int givenCapacity);
void  OStack_delete(OStack* _this);
Boolean  OStack_isEmpty(OStack* _this);
Boolean OStack_isFull(OStack* _this);
int  OStack_size(OStack* _this);
Boolean  OStack_push(OStack* _this, char anElement);
Element  OStack_pop(OStack* _this);

void  OStack_deleteLinkedChain(OStack* _this);
void OStack_showLinkedChain(OStack* _this);

int OStack_topElement(OStack* _this);

#endif