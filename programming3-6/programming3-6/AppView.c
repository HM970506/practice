#include "AppView.h"
#include "Keyboad.h"
#include <stdio.h>

void AppView_out(char* aString)
{
	printf("%s", aString);
}

Boolean AppView_in_doesContinueToInputNextStudent()
{
	printf("\n? 성적을 입력하려면 'Y'를, 입력을 종료하려면 다른 아무 키나 치시오 ");
	char answer = getcharDirectlyFromKeyboard();
	printf("%c", answer);

	
	if (answer == 'Y' || answer == 'y') return TRUE;
	else
	{
		printf("\n입력을 종료합니다.\n");
		return FALSE;
	}
}

int AppView_in_score()
{
	int score=0;
	printf("\n- 점수를 입력하시오: ");
	scanf_s("%d", &score);
	return score;
}

void AppView_out_averageScore(float anAverage)
{
	printf("\n평균점수는 %f 입니다.\n",anAverage);
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
void AppView_out_studentInfo(int aScore, int aGrade)
{
	printf("점수:%d 학점:%c\n", aScore, aGrade);
}

