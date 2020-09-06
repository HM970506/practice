#ifndef Queue_h
#define Queue_h

typedef struct _Queue Queue;
typedef char Element;
typedef enum _Boolean Boolean;

Queue* Queue_new(int givenCapacity);
void  Queue_delete(Queue* _this);
Boolean Queue_add(Queue* _this, Element anElement);

Element Queue_remove(Queue* _this);
Element Queue_size(Queue* _this);
void AppView_out_noElementInQueue();
char Queue_frontNode(Queue* _this);

Boolean Queue_isEmpty(Queue* _this);
Boolean Queue_isFull(Queue* _this);
Element  Queue_elementAt(Queue* _this, int anOrder);
int Queue_nextRear(Queue* _this);
int Queue_nextFront(Queue* _this);

#endif
