#ifndef Traverse_h
#define Traverse_h


typedef struct _Object Object;
typedef struct _Key Key;

typedef struct _Traverse  Traverse;
Traverse* Traverse_new(void);
void Traverse_delete (Traverse* _this) ;
void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int depth);

#endif