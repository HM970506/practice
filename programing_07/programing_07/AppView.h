#ifndef List_AppView_h
#define List_AppView_h

#include "Common.h"
#include "AppController.h"

void AppView_out(char* aString);
void AppView_out_averageScore(float anAverage);
void AppView_out_numberOfStudentsAboveAverage(int aNumber);
void AppView_out_maxScore(int aMaxScore);
void AppView_out_minScore(int aMinScore);
void AppView_out_gradeCountFor(char aGrade, int aCount);
void AppView_out_studentInfo(char* studentID, int aScore, char aGrade);

Boolean AppView_in_doesContinueToInputNextStudent();
int AppView_in_score();

void  AppView_in_studentID(char* aStudentID);
void  AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength);
void  AppView_out_msg_invalidScore();

void AppView_out_titleForSortedStudentList();
#endif