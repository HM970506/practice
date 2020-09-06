#ifndef AppController_h
#define AppController_h

typedef struct _AppCotroller AppController;
typedef struct _Traverse Traverse;

AppController* AppController_new();
void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse);
void AppController_run(AppController* appcontroller);
void AppController_delete(AppController* appcontroller);

#endif