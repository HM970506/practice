#ifndef ListTimer_UnlinkedList_h
#define ListTimer_UnlinkedList_h

typedef enum _Boolean Boolean;
typedef int Element;
typedef struct _Node Node;

typedef struct _UnsortedLinkedList
{
	int  _size;
	Node* _head;

}UnsortedLinkedList;

UnsortedLinkedList* UnsortedLinkedList_new();
void  UnsortedLinkedList_delete(UnsortedLinkedList* _this);
Boolean  UnsortedLinkedList_isEmpty(UnsortedLinkedList* _this);
Boolean  UnsortedLinkedList_isFull(UnsortedLinkedList* _this);
Boolean  UnsortedLinkedList_add(UnsortedLinkedList* _this, Element anElement);
Element  UnsortedLinkedList_min(UnsortedLinkedList* _this);
Element  UnsortedLinkedList_removeMax(UnsortedLinkedList* _this);

#endif