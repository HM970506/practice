#include "Ban.h"
#include "AppController.h"
#pragma warning(disable: 6011)


typedef struct _Ban {
	int _capacity;
	int _size;
	Student** _elements; //배열내부라서 * + 구조체콜바이레퍼런스라서 *
	GradeCounter* _gradeCounter;
}Ban;

Boolean Ban_scoreIsValid(int aScore)
{
	return (aScore >= 0 && aScore <= 100); //점수가 범위내
}
char Ban_scoreToGrade(int aScore)
{
	if (aScore >= 90) return 'A';
	else if (aScore >= 80) return 'B';
	else if (aScore >= 70) return 'C';
	else if (aScore >= 60) return 'D';
	else return 'F';
}

Ban* Ban_new()
{
	Ban* _this = NewObject(Ban);

	_this->_capacity = DEFAULT_CAPACITY; //최대학생수
	_this->_size = 0;
	_this->_elements = NewVector(Student*, _this->_capacity);
	return _this;

}
Ban* Ban_newWithCapacity(int givenCapacity)
{
	Ban* _this = Ban_new();

	_this->_capacity = givenCapacity;
	_this->_size = 0;

	return _this;
}

void Ban_delete(Ban* _this)
{
	for (int x = 0; x < _this->_size; x++)
	{
		free(_this->_elements[x]);
	}
	free(_this);
}


int Ban_capacity(Ban* _this)
{
	return (_this->_capacity);
}

int Ban_size(Ban* _this)
{
	return (_this->_size);
}

Boolean Ban_isEmpty(Ban* _this)
{
	return (_this->_size == 0);
}

Boolean Ban_isFull(Ban* _this)
{
	return (_this->_size >= _this->_capacity);
}

Boolean Ban_add(Ban* _this, Student* aStudent)
{
	if (Ban_isFull(_this)) return FALSE;
	else {
		_this->_elements[_this->_size] = aStudent;
		_this->_size++;

		return TRUE;
	}
}

Student* Ban_elementAt(Ban* _this, int anOrder)
{
	if (anOrder >= _this->_size) return NULL;  //값없음
	else return(_this->_elements[anOrder]);  //값있음
}

void Ban_sortStudentsByScore(Ban* _this)
{
	Ban_quickSort(_this);
}

void Ban_quickSort(Ban* _this)
{
	int size = Ban_size(_this);

	if (size >= 2)
	{
		int minPosition = 0;
		for (int x = 0; x < size; x++)
		{
			if (Student_score(_this->_elements[x]) < Student_score(_this->_elements[minPosition]))
				minPosition = x;
		}
		SWAP(Student*, _this->_elements[minPosition], _this->_elements[size - 1]);
	}
	Ban_quickSortRecursively(_this, 0, size - 2);
}

void Ban_quickSortRecursively(Ban* _this, int left, int right)
{
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}

int Ban_partition(Ban* _this, int left, int right) //퀵소트 일부
{
	int pivot = left;
	int pivotScore = Student_score (_this->_elements[pivot]);
	right++;

	do {
		do { left++; } while (Student_score (_this->_elements[left]) > pivotScore);
		do { right--; } while (Student_score (_this->_elements[right]) < pivotScore);
		if (left < right) SWAP(Student*, _this->_elements[left], _this->_elements[right]); //문제발생
	} while (left < right);
	SWAP(Student*, _this->_elements[pivot], _this->_elements[right]);
	return right;
}

float Ban_averageScore(Ban* _this)
{
	float sumOfScores = (float)Ban_sumOfScoreRecursively(_this, 0, _this->_size - 1);
	float average = sumOfScores / (float)_this->_size;
	return average;
}
int Ban_minScore(Ban* _this)
{
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}
int Ban_maxScore(Ban* _this)
{
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right)
{ 
	if (left > right) return 0;
	else
	{
		int score = Student_score ( _this->_elements[left] ) ;
		return  (score + Ban_sumOfScoresRecursively(_this, left+1, right) ) ;
	} 
}


int Ban_sumOfScoreRecursively(Ban* _this, int left, int right)
{
	if (left > right) return 0;
	else return (Student_score(_this->_elements[left]) + Ban_sumOfScoreRecursively(_this, left + 1, right));
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right) //분할정복기법
{
	if (left < 0 || right >= _this->_size) return -1; //맵밖

	int mid = (left + right) / 2;
	if (mid == left || mid == right)
	{
		if (Student_score(_this->_elements[left]) > Student_score(_this->_elements[right])) return Student_score(_this->_elements[left]);
		else return Student_score(_this->_elements[right]);
	}
	int left_max = Ban_maxScoreRecursively(_this, left, mid);
	int right_max = Ban_maxScoreRecursively(_this, mid, right);

	if (left_max > right_max) return left_max;
	else return right_max;

}

int Ban_minScoreRecursively(Ban* _this, int left, int right)
{
	if (left < 0 || right >= _this->_size) return 101;

	if (left == right) return Student_score(_this->_elements[left]);
	else
	{
		int min1;
		int min2;
		if (Student_score(_this->_elements[left]) < Student_score(_this->_elements[right]))
		{
			min1 = Student_score(_this->_elements[left]);
			min2 = Ban_minScoreRecursively(_this, left, right - 1);
		}
		else
		{
			min1 = Student_score(_this->_elements[right]);
			min2 = Ban_minScoreRecursively(_this, left + 1, right);
		}

		if (min1 > min2) return min2;
		else return min1;
	}

}

int Ban_numberOfStudentsAboveAberage(Ban* _this)
{
	float average = Ban_averageScore(_this);
	int score;
	int numberOfStudentsAboveAverage = 0;

	for (int x = 0; x < _this->_size; x++)
	{
		score = Student_score(_this->_elements[x]);
		if (((float)Student_score(_this->_elements[x])) >= average) numberOfStudentsAboveAverage++;
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_counterGrade(Ban* _this)
{
	char currentGrade;
	int score;
	GradeCounter* gradeCounter = GradeCounter_new();

	for (int x = 0; x < _this->_size; x++)
	{
		score = Student_score(_this->_elements[x]);
		currentGrade = Ban_scoreToGrade(score);
		GradeCounter_count(gradeCounter, currentGrade); 
	}
	return gradeCounter;
}