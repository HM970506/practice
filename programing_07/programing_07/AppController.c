#include "Student.h"
#include "AppView.h"
#include "Ban.h"
#pragma warning(disable: 6011)

#undef AppController

typedef struct _AppController
{
	Ban* _ban;
}AppController;

AppController* AppController_new()
{
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_newWithCapacity(MAX_STUDENT_ID_LENGTH);
	return _this;
}

Boolean AppController_inputIsValid (AppController* _this, char* aStudentID, int aScore)
{
	Boolean  inputIsValid = TRUE;
	if ( ! Student_studentIDIsValid (aStudentID) )
	{
		AppView_out_msg_invalidStudentID(aStudentID, MAX_STUDENT_ID_LENGTH);
		inputIsValid = FALSE;
	}
	if ( ! Student_scoreIsValid (aScore) )
	{
		AppView_out_msg_invalidScore(aScore) ;
		inputIsValid = FALSE; } return  inputIsValid;
}

Boolean  AppController_inputAndStoreStudents (AppController* _this)
{
	int  score ;
	Boolean storingAStudentWasSuccessful = TRUE ;
	char studentID[100] ;
	Student* student ; 

	while ( storingAStudentWasSuccessful && AppView_in_doesContinueToInputNextStudent () ) 
	{ 
		AppView_in_studentID (studentID) ;
		score = AppView_in_score () ;
	
		if ( AppController_inputIsValid (_this, studentID, score) ) 
		{
			student = Student_new (studentID, score) ; 
			storingAStudentWasSuccessful = Ban_add (_this->_ban, student) ;
		}
	}
	return  storingAStudentWasSuccessful ;
}
void  AppController_showStudentsSortedByScore(AppController* _this)
{
	Student* student; 
	AppView_out_titleForSortedStudentList(); 
	
	for (int i = 0; i < Ban_size(_this->_ban); i++)
	{ 
		student = Ban_elementAt(_this->_ban, i); 

		int score = Student_score(student);
		char grade = Ban_scoreToGrade(score);
		char* ID = Student_studentID(student);
		AppView_out_studentInfo(ID, score, grade);
	}
}


void AppController_run(AppController* _this)
{
	AppView_out("<<<성적 처리를 시작합니다>>>\n");

	Boolean inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
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


void AppController_delete(AppController* _this)
{
	free(_this);
}