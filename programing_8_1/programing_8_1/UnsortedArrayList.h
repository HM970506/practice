#ifndef ListTiemr_UnsortedArrayList_h
#define ListTiemr_UnsortedArrayList_h

typedef int Element;
typedef enum _Boolean Boolean;

typedef struct _UnsortedArrayList
{
	int _capacity;
	int _size;
	Element* _elements;
}UnsortedArrayList;


UnsortedArrayList* UnsortedArrayList_new(int givenCapacity);
void  UnsortedArrayList_delete(UnsortedArrayList* _this);
Boolean  UnsortedArrayList_isEmpty(UnsortedArrayList* _this);
Boolean  UnsortedArrayList_isFull(UnsortedArrayList* _this);
Boolean  UnsortedArrayList_add(UnsortedArrayList* _this, Element anElement);
Element  UnsortedArrayList_removeMax(UnsortedArrayList* _this);

int UnsortedArrayList_maxPositionRecursively(UnsortedArrayList* _this, int left, int right);
Element UnsortedArrayList_removeAt(UnsortedArrayList* _this, int maxPosition);

#endif
