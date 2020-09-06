#ifndef List_Student_h
#define List_Student_h

#include "Common.h"

Boolean Student_studentIDIsValid(char* aStudentID);
Boolean  Student_scoreIsValid(int aScore);

typedef struct _Student Student;

Student* Student_new(char* givenStudentID, int givenScore);
void Student_delete(Student* _this);
char* Student_studentID(Student* _this); 
int Student_score(Student* _this);

#endif