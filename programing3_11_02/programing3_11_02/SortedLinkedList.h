#ifndef ListTimer_SortedLinkedList_h
#define ListTimer_SortedLinkedList_h

typedef enum _Boolean Boolean;
typedef int Element;
typedef struct _Node Node;

typedef struct  _SortedLinkedList {
	int  _size;
	Node* _head;
}SortedLinkedList;

SortedLinkedList* SortedLinkedList_new(void); 
void  SortedLinkedList_delete(SortedLinkedList* _this); 
Boolean  SortedLinkedList_isEmpty(SortedLinkedList* _this);
Boolean  SortedLinkedList_isFull(SortedLinkedList* _this);
Boolean  SortedLinkedList_add(SortedLinkedList* _this, Element anElement);
Element  SortedLinkedList_min(SortedLinkedList* _this);
Element  SortedLinkedList_removeMax(SortedLinkedList* _this);

#endif