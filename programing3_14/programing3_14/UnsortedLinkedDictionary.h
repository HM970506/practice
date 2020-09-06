UnsortedLinkedDictionary* UnsortedLinkedDictionary_new(int maxSize);
 void UnsortedLinkedDictionary_delete(UnsortedLinkedDictionary* _this);
 Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this);
 Boolean UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary* _this);
 void UnsortedLinkedDictionary_addKeyAndObject(UnsortedLinkedDictionary* _this, Key* aKey, Object* anObject);
 Boolean UnsortedLinkedDictionary_keyDoesExist(UnsortedLinkedDictionary* _this, Key* aKey);
 Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictiona#ifndef ListTimer_UnlinkedList_h
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

#endifry* _this, Key* aKey);