#ifndef AppView_h
#define AppView_h

char getCharDirectlyFromKeyboard();
void AppView_out_startProgram();
char AppView_in_nextInputChar();
void AppView_out_queueIsFull(char aChar);
void AppView_out_noElementInQueue();
void AppView_out_removedElementFromQueue(char removedChar);
void AppView_out_removedElementFromQueueN(char removedChar);
void AppView_out_ignore();
void AppView_out_showsize(int input);
void AppView_out_elementInQueue(char input);
void AppView_out_addedElementInQueue(char aChar);

void AppView_out_labelstart();
void AppView_out_labelend();
void AppView_showFront(char front);
void AppView_out_endProgram();
void AppView_out_Esc(char deleteElement);

void AppView_out_Esc1(int input);
void AppView_out_Esc2(int input);
void AppView_out_Esc3(int input);
void AppView_out_Esc4(int input);

#endif
