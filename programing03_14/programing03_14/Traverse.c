#include "Traverse.h"
#include "Key.h"
#include "Common.h"
#include "Object.h"
#include "AppView.h"

struct _Traverse {
    int test;
};

Traverse* Traverse_new(void)
{
    Traverse* _this = NewObject(Traverse);
    return _this;
}

void Traverse_delete(Traverse* _this)
{
    free(_this);
}

void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int depth)
{
    for(int x=0; x<depth; x++)
    {
        AppView_out_space();
    }
    AppView_out_key(aKey);
}

