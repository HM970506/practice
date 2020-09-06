SortedLinkedDictionary* SortedLinkedDictionary_new(int maxSize);
 void SortedLinkedDictionary_delete(SortedLinkedDictionary* _this);
 Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this);
 Boolean SortedLinkedDictionary_isFull(SortedLinkedDictionary* _this);
 void SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary* _this, Key* aKey, Object* anObject);
 Boolean SortedLinkedDictionary_keyDoesExist(SortedLinkedDictionary* _this, Key* aKey);
 Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary* _this, Key* aKey);

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