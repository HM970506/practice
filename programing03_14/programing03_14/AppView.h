#ifndef AppView_h
#define AppView_h

typedef struct _Object Object;
typedef struct _Key Key;

void AppView_out(char* aString);
void AppView_out_space();
void AppView_out_key(Key* aKey);
void AppView_out_start();
int AppView_in();
void AppView_out_replace(int inputChar);
void AppView_keydelete(Key* aKey, Object* anObject);
void AppView_out_search(Key* aKey, Object* anObject);
void AppView_out_showsize(int input);
void AppView_out_add(Key* aKey, Object* anObject);
void AppView_out_search(Key* aKey, Object* anObject);
#endif