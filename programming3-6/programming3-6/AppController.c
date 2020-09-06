#include "AppController.h"
#include "AppView.h"
#pragma warning(disable: 6011)

AppController* AppController_new()
{
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	return _this;

}
void AppController_run(AppController* _this)
{
	AppView_out("<<<성적 처리를 시작합니다>>>\n");

	Boolean inputAndStoreWasSuccessful=AppController_inputAndStoreStudents(_this);

	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppView_out("\n[오류] 학생 정보가 전혀 입력되지 않았습니다.\n"); //1명이상입력
		}
		else
		{
			AppController_showStatistics(_this); //출력
			Ban_sortStudentsByScore(_this->_ban); //성적순 정렬
			AppController_showStudentsSortedByScore(_this); //학생성적출력
		}
	}
	else AppView_out("[오류]성적이 정상적으로 입력되지 않았습니다.");
	AppView_out("\n<<<성적 처리를 종료합니다>>>\n");
	system("pause");
}

Boolean AppController_inputAndStoreStudents(AppController* _this) 
{
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;

	while (storingAStudentWasSuccessful && AppView_in_doesContinueToInputNextStudent())
	{
		score = AppView_in_score();
		if (Ban_scoreIsValid(score)) storingAStudentWasSuccessful = Ban_add(_this->_ban, score);
		else AppView_out("[오류] 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
	}
	return storingAStudentWasSuccessful;
}

void AppController_showStatistics(AppController* _this)
{
	AppView_out_averageScore(Ban_averageScore(_this->_ban));
	AppView_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAberage(_this->_ban));
	AppView_out_maxScore(Ban_maxScore(_this->_ban));
	AppView_out_minScore(Ban_minScore(_this->_ban));

	GradeCounter* gradeCounter = Ban_counterGrade(_this->_ban);
	AppView_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppView_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppView_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppView_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppView_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter);
}

void AppController_showStudentsSortedByScore(AppController* _this)
{
	AppView_out("\n학생들의 성적순 목록입니다\n");

	int score;
	char grade;

	for (int order = 0; order < Ban_size(_this->_ban); order++)
	{
		score = Ban_elementAt(_this->_ban, order);
		grade = Ban_scoreToGrade(score);
		AppView_out_studentInfo(score, grade);
	}
}

void AppController_delete(AppController* _this)
{
	free(_this);
}