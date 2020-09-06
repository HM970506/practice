#include "Ban.h"
#pragma warning(disable: 6011)

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
	_this->_elements = NewVector(int, _this->_capacity);
	return _this;

}
Ban* Ban_newWithCapacity(int givenCapacity)
{
	Ban* _this = NewObject(Ban);

	_this->_capacity = givenCapacity;
	_this->_size = 0;
	_this->_elements = NewVector(int, _this->_capacity);
	return _this;
}

void Ban_delete(Ban* _this)
{
	free(_this->_elements);
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

Boolean Ban_add(Ban* _this, int aScore)
{
	if (Ban_isFull(_this)) return FALSE;
	else {
		_this->_elements[_this->_size] = aScore;
		_this->_size++;


		return TRUE;
	}
}

int Ban_elementAt(Ban* _this, int anOrder)
{
	if (anOrder >= _this->_size) return -1;  //값없음
	else return(_this->_elements[anOrder]);  //값있음
}

void Ban_sortStudentsByScore(Ban* _this)
{
	int size = _this->_size;
	if (size >= 2)
	{
		int minPosition = 0;
		for (int x = 1; x < size; x++)
		{
			if (_this->_elements[x] < _this->_elements[minPosition]) minPosition = x; //최솟값
		}
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]); //최솟값은 맨끝에
		Ban_quickSortRecursively(_this, 0, size - 2); //정렬
	}
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
	int pivotScore = _this->_elements[pivot];
	right++;

	do {
		do {left++; } while (_this->_elements[left] > pivotScore);
		do {right--; } while (_this->_elements[right] < pivotScore);
		if (left < right) SWAP(int, _this->_elements[left], _this->_elements[right]); //문제발생
	} while (left < right);
		SWAP(int, _this->_elements[pivot], _this->_elements[right]);
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

int Ban_sumOfScoreRecursively(Ban* _this, int left, int right)
{
	if (left > right) return 0;
	else return (_this->_elements[left] + Ban_sumOfScoreRecursively(_this, left + 1, right));
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right) //분할정복기법
{
	if (left < 0 || right >= _this->_size) return -1; //맵밖

	int mid = (left + right) / 2;
	if (mid == left || mid == right)
	{
		if (_this->_elements[left] > _this->_elements[right]) return _this->_elements[left];
		else return _this->_elements[right];
	}
	int left_max = Ban_maxScoreRecursively(_this, left, mid);
	int right_max = Ban_maxScoreRecursively(_this, mid, right);

	if (left_max > right_max) return left_max;
	else return right_max;
	
}

int Ban_minScoreRecursively(Ban* _this, int left, int right)
{
	if (left < 0 || right >= _this->_size) return 101;

	if (left == right) return _this->_elements[left];
	else
	{
		int min1;
		int min2;
		if (_this->_elements[left] < _this->_elements[right])
		{
			min1 = _this->_elements[left];
			min2 = Ban_minScoreRecursively(_this, left, right - 1);
		}
		else
		{
			min1 = _this->_elements[right];
			min2 = Ban_minScoreRecursively(_this, left+1, right);
		}

		if (min1 > min2) return min2;
		else return min1;
	}

}

int Ban_numberOfStudentsAboveAberage(Ban* _this)
{
	float average = Ban_averageScore(_this);
	int numberOfStudentsAboveAverage = 0;

	for (int x = 0; x < _this->_size; x++)
	{
		if (((float)_this->_elements[x]) >= average) numberOfStudentsAboveAverage++;
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_counterGrade(Ban* _this)
{
	char currentGrade;
	GradeCounter* gradeCounter = GradeCounter_new();
	
	for (int x = 0; x < _this->_size; x++)
	{
		currentGrade = Ban_scoreToGrade(_this->_elements[x]);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}