#ifndef Infix_VStack_h
#define Infix_VStack_h

typedef  char  ElementForVStack;
typedef int Element;
typedef struct _VStack VStack;
typedef enum _Boolean Boolean;

ElementForVStack  VStack_elementAt(VStack* _this, int order);
ElementForVStack  VStack_peek(VStack* _this);

VStack* VStack_new(int givenCapacity);
void  VStack_delete(VStack* _this);
Boolean  VStack_isEmpty(VStack* _this);
Boolean VStack_isFull(VStack* _this);
int  VStack_size(VStack* _this);
Boolean  VStack_push(VStack* _this, Element anElement);
Element VStack_pop(VStack* _this);

void VStack_deleteLinkedChain(VStack* _this);
void VStack_showLinkedChain(VStack* _this);



#endif