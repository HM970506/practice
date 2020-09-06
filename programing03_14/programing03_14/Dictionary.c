#include "Dictionary.h"
#include "Common.h"
#include "Object.h"
#include "Key.h"
#include "BinaryNode.h"
#include "Traverse.h"
#pragma warning(disable:4715)

struct  _Dictionary { 

	BinaryNode* _root;
	int _size;
};

int Dictionary_size(Dictionary* _this)
{
	return _this->_size;
}

BinaryNode* Dictionary_root(Dictionary* _this)
{
	return _this->_root;
}

Key* Dictionary_root_key(Dictionary* _this)
{
	return BinaryNode_key(Dictionary_root(_this));
}

Dictionary* Dictionary_new()
{
	Dictionary* _this = NewObject(Dictionary);
	_this->_root = NULL;
	return _this;
}

void Dictionary_delete(Dictionary* _this) 
{ 
	Dictionary_deleteBinaryNodes (_this, _this->_root) ;
	free (_this) ;
}

void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode* aNode)
{ 
	if (aNode != NULL) {
		Dictionary_deleteBinaryNodes(_this, BinaryNode_left(aNode)); 
		Dictionary_deleteBinaryNodes(_this, BinaryNode_right(aNode));
		BinaryNode_delete(aNode);
	}
}

Boolean  Dictionary_isEmpty(Dictionary* _this) {
	return  (_this->_root == NULL);  
}

Boolean  Dictionary_isFull(Dictionary* _this) 
{
	return  (FALSE);
}

Boolean  Dictionary_keyDoesExist(Dictionary* _this, Key* aKey) 
{ 
	if ((Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL)) return TRUE;
	else return FALSE;
}

Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey) 
{ 
	return Dictionary_searchTreeRecursively(_this, aKey, _this->_root);
}

Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode)
{ 
	if (aNode == NULL)  return  NULL; 
	else { 
		if (Key_compareTo(aKey, BinaryNode_key(aNode)) == 0)
			return (BinaryNode_object(aNode));
		else if (Key_compareTo(aKey, BinaryNode_key(aNode)) < 0)
		 return Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode));
		else return Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode));
	}
}

Boolean  Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject)
{
	if (_this->_root == NULL)
	{
		_this->_root = BinaryNode_newWith(aKey, anObject, NULL, NULL); 
		_this->_size = 1;
		return  (TRUE);
	}

	else return  (Dictionary_addToTree(_this, aKey, anObject, _this->_root));

}

Boolean  Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent)
{ 
	if ( Key_compareTo(aKey, BinaryNode_key(parent)) < 0 ) 
	{
		if (BinaryNode_left (parent) == NULL )
		{ 
		BinaryNode_setLeft (parent, BinaryNode_newWith (aKey, anObject, NULL, NULL) ) ;
		_this->_size++ ; 
		return  TRUE; 
		} 
	else return Dictionary_addToTree (_this, aKey, anObject, BinaryNode_left(parent) ) ; 
	} 
	else if ( Key_compareTo(aKey, BinaryNode_key(parent)) > 0 ) 
	{
		if (BinaryNode_right(parent) == NULL)
		{
			BinaryNode_setRight(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			_this->_size++;
			return  TRUE;
		}
		else return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
	} 
	else  { 

		if(Key_compareTo (aKey, BinaryNode_key(parent)) == 0)
		return  FALSE; 
	} 
}

Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey)
{
	if (Dictionary_isEmpty(_this)) return NULL;
	else {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_root)) != 0)
			return  Dictionary_removeFromTreeRecursively(_this, aKey, _this->_root);
		else {
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) _this->_root = BinaryNode_right(_this->_root);
			else if (BinaryNode_right(_this->_root) == NULL)  _this->_root = BinaryNode_left(_this->_root);
			else { 
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, _this->_root);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				_this->_root = rightmost;
			}
			Object* removedObject = BinaryNode_object(removedNode);
			ObjectValue test = Object_value(removedObject);
			BinaryNode_delete(removedNode);
			_this->_size--;
			Object_setValue(removedObject, test);
			return  removedObject;
		}
	}
}

Boolean  Dictionary_replaceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject)
{
	if (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL)
		BinaryNode_setObject(_this->_root, anObject);
	else return FALSE;
}

Object* Dictionary_removeFromTreeRecursively(Dictionary * _this, Key * aKey, BinaryNode * parent)
{ 
	if ( Key_compareTo (aKey, BinaryNode_key(parent)) < 0 ) 
	{
		BinaryNode*  leftChild = BinaryNode_left (parent) ; 
		if ( leftChild == NULL ) return NULL ; 
		
		if ( Key_compareTo (aKey, BinaryNode_key (leftChild)) == 0 )
		{ 
			BinaryNode*  removedNode = leftChild ; 
			if (BinaryNode_left(removedNode) == NULL)
				BinaryNode_setLeft(parent, BinaryNode_right(removedNode));

			else if (BinaryNode_right(removedNode) == NULL)
				BinaryNode_setLeft(parent, BinaryNode_left(removedNode));

			else { 
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree (_this, removedNode) ;
				BinaryNode_setLeft (rightmost, BinaryNode_left (removedNode)) ;
				BinaryNode_setRight (rightmost, BinaryNode_right (removedNode)) ;
				BinaryNode_setLeft (parent, rightmost) ; 
			} 
			Object* removedObject = BinaryNode_object(removedNode);
			ObjectValue test = Object_value(removedObject);
			BinaryNode_delete(removedNode);
			_this->_size--;
			Object_setValue(removedObject, test);
			return  removedObject;
		} 
		else return  Dictionary_removeFromTreeRecursively (_this, aKey, leftChild) ; 
	} 
	else {
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) return NULL;

		if (Key_compareTo(aKey, BinaryNode_key(rightChild)) == 0)
		{
			BinaryNode* removedNode = rightChild;
			if (BinaryNode_left(removedNode) == NULL)
				BinaryNode_setRight(parent, BinaryNode_right(removedNode));

			else if (BinaryNode_right(removedNode) == NULL)
				BinaryNode_setRight(parent, BinaryNode_left(removedNode));

			else {
				BinaryNode* leftmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setRight(leftmost, BinaryNode_left(removedNode));
				BinaryNode_setLeft(leftmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, leftmost);
			}

			Object* removedObject = BinaryNode_object(removedNode);
			ObjectValue test = Object_value(removedObject);
			BinaryNode_delete(removedNode);
			_this->_size--;
			Object_setValue(removedObject, test);
			return  removedObject;
		}
		else return  Dictionary_removeFromTreeRecursively(_this, aKey, rightChild);
	} 
}

BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfSubtree) 
{ 
	BinaryNode*  leftOfRoot = BinaryNode_left (rootOfSubtree) ; 
	BinaryNode*  rightmost = leftOfRoot ;
	if (BinaryNode_right(leftOfRoot) == NULL)
	{
		BinaryNode_setLeft(rootOfSubtree, BinaryNode_left(leftOfRoot));
		BinaryNode_setLeft(rightmost, NULL);
		return  rightmost;
	}
	else { 
		BinaryNode*  parentOfRightmost = NULL ; 
		do {
			parentOfRightmost = rightmost ; 
			rightmost = BinaryNode_right(rightmost) ;
		} while ( BinaryNode_right(rightmost) != NULL ) ;
		BinaryNode_setRight (parentOfRightmost, BinaryNode_left (rightmost) ) ;
	} 
	BinaryNode_setLeft (rightmost, NULL) ;  
	return  rightmost ;
}

void  Dictionary_scanInSortedOrder(Dictionary * _this, Traverse * aTraverse)
{
 Dictionary_inorderRecursively(_this, aTraverse, _this->_root, 1);
}

void Dictionary_inorderRecursively(Dictionary * _this, Traverse * aTraverse, BinaryNode * aRoot, int depth) 
{
	if (depth == 0) Traverse_visit(aTraverse, BinaryNode_key(aRoot), BinaryNode_object(aRoot), depth);

	if (aRoot != NULL) 
	{
	Dictionary_inorderRecursively(_this, aTraverse, BinaryNode_right(aRoot), depth + 1);
	if(depth!=0) Traverse_visit(aTraverse, BinaryNode_key(aRoot), BinaryNode_object(aRoot), depth);
	Dictionary_inorderRecursively(_this, aTraverse, BinaryNode_left(aRoot), depth + 1);
	}
}
