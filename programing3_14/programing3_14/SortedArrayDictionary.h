SortedArrayDictionary* SortedArrayDictionary_new(int maxSize);
 void SortedArrayDictionary_delete(SortedArrayDictionary* _this);
 Boolean SortedArrayDictionary_isEmpty(SortedArrayDictionary* _this);
 Boolean SortedArrayDictionary_isFull(SortedArrayDictionary* _this);
 void SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary* _this, Key* aKey, Object* anObject);
 Boolean SortedArrayDictionary_keyDoesExist(SortedArrayDictionary* _this, Key* aKey);
 Element* SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary* _this, Key* aKey);

#ifndef ListTimer_SortedArrayList_h
#define ListTimer_SortedArrayList_h

typedef enum _Boolean Boolean;
typedef  struct _SortedArrayList  SortedArrayList;
typedef int Element;

SortedArrayList* SortedArrayList_new(int givenCapacity);
void  SortedArrayList_delete(SortedArrayList* _this);
Boolean SortedArrayList_isEmpty(SortedArrayList* _this);
Boolean SortedArrayList_isFull(SortedArrayList* _this);
Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement);
Element SortedArrayList_removeMax(SortedArrayList* _this);
Element SortedArrayList_min(SortedArrayList* _this);
void SortedArrayList_addAt(SortedArrayList* _this, Element anElement, int aPosition);
Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition);
int SortedArrayList_positionUsingBinarySearch(SortedArrayList* _this, Element anElement);

#endif