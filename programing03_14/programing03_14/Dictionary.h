#ifndef Dictionary_h
#define Dictionary_h

typedef struct _Dictionary Dictionary;
typedef struct  _BinaryNode  BinaryNode;
typedef struct _Traverse Traverse;
typedef enum _Boolean Boolean;
typedef struct _Key Key;
typedef struct _Object Object;

Dictionary* Dictionary_new(void);
void  Dictionary_delete(Dictionary* _this);
Boolean  Dictionary_isEmpty(Dictionary* _this);
Boolean Dictionary_isFull(Dictionary* _this); 
int Dictionary_size(Dictionary* _this);
Boolean  Dictionary_keyDoesExist(Dictionary* _this, Key* aKey);
Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey);
Boolean  Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject);
Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey);
Boolean  Dictionary_replaceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject);
void  Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse);
void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode* aNode);
Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode);
Boolean  Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfSubtree);
void Dictionary_inorderRecursively(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int depth);
BinaryNode* Dictionary_root(Dictionary* _this);
Key* Dictionary_root_key(Dictionary* _this);
#endif