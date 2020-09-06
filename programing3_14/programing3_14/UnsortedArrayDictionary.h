#ifndef ListTiemr_UnsortedArrayList_h
#define ListTiemr_UnsortedArrayList_h

typedef  struct _UnsortedArrayList UnsortedArrayList;

typedef enum _Boolean Boolean;
typedef struct _Node Node;
typedef struct _Key Key;
typedef struct _Object Object;
typedef Node Element;

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize);
void UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this);
Boolean UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this);
Boolean UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this);

void UnsortedArrayDictionary_addKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey);
Element* UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey);



#endif
