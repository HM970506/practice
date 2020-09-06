#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include "Student.h"
#include "Keyboard.h"
#include <stdio.h>
#pragma warning(disable: 6031)


void AppView_out(char* aString)
{
	printf("%s", aString);
}

Boolean AppView_in_doesContinueToInputNextStudent()
{
	printf("\n? 학생정보를 입력하려면 'Y'를, 입력을 종료하려면 다른 아무 키나 치시오 ");
	char answer = getcharDirectlyFromKeyboard();
	printf("%c", answer);


	if (answer == 'Y' || answer == 'y') return TRUE;
	else
	{
		printf("\n입력을 종료합니다.\n");
		return FALSE;
	}
}

void  AppView_in_studentID(char* aStudentID)
{
	printf("\n- 학번을 입력하시오: ");
	scanf("%s", aStudentID);
}


int AppView_in_score()
{
	int score;
	printf("- 점수를 입력하시오: ");
	scanf("%d", &score);
	return score;
}

void AppView_out_averageScore(float anAverage)
{
	printf("\n평균점수는 %f 입니다.\n", anAverage);
}
void AppView_out_numberOfStudentsAboveAverage(int aNumber)
{
	printf("평균 이상인 학생은 모두 %d명 입니다.\n", aNumber);
}
void AppView_out_maxScore(int aMaxScore)
{
	printf("최고점은 %d 점 입니다.\n", aMaxScore);
}
void AppView_out_minScore(int aMinScore)
{
	printf("최저점은 %d 점 입니다.\n\n", aMinScore);
}
void AppView_out_gradeCountFor(char aGrade, int aCount)
{
	printf("%c 학점은 %d명 입니다.\n", aGrade, aCount);
}
void AppView_out_studentInfo(char* studentID, int aScore, char aGrade)
{ 
	printf("학번: %s, 점수: %d, 학점: %c\n", studentID, aScore, aGrade);
}

void  AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength)
{
	printf("[오류] 학번 %s 의 길이가 너무 깁니다. 최대 %d 입니다.\n", aStudentID, maxLength);
}

void  AppView_out_msg_invalidScore()
{
	printf("[오류] 0 보다 작거나 100 보다 커서, 정상적인 점수가 아닙니다.\n");
}

void AppView_out_titleForSortedStudentList()
{
	printf("\n학생의 성적순 목록입니다.\n");

}
