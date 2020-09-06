#pragma once
#ifndef List_Ban_h
#define List_Ban_h

#include "GradeCounter.h"
#include "Student.h"

#define DEFAULT_CAPACITY 100

typedef struct _Ban Ban;
typedef struct _AppController AppController;

Ban* Ban_new();
Ban* Ban_newWithCapacity(int givenCapacity);

void Ban_delete(Ban* _this);
int Ban_capacity(Ban* _this);
int Ban_size(Ban* _this);
Boolean Ban_isEmpty(Ban* _this);
Boolean Ban_isFull(Ban* _this);
Boolean Ban_add(Ban* _this, Student* aStudent);
Student* Ban_elementAt(Ban* _this, int anOrder);
void Ban_sortStudentsByScore(Ban* _this);
void Ban_quickSortRecursively(Ban* _this, int left, int right);
void Ban_quickSort(Ban* _this);
int Ban_partition(Ban* _this, int left, int right);

int Ban_minScore(Ban* _this);
int Ban_maxScore(Ban* _this);
float Ban_averageScore(Ban* _this);

Boolean Ban_scoreIsValid(int aScore);
char Ban_scoreToGrade(int aScore);

int Ban_sumOfScoreRecursively(Ban* _this, int left, int right);
int Ban_maxScoreRecursively(Ban* _this, int left, int right);
int Ban_minScoreRecursively(Ban* _this, int left, int right);


int Ban_numberOfStudentsAboveAberage(Ban* _this);
GradeCounter* Ban_counterGrade(Ban* _this);

#endif