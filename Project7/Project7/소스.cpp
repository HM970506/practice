#include <iostream>
using namespace std;

int map1[3] = { 1,2,3 };
int map2[3] = { 0 };
int map3[3] = { 0 };

void move(int from, int to)
{
	cout << from << "에서 " << to << "로 옮김" << endl;
}

void hanoi(int n, int from, int by, int to) //탑개수, 1.2.3번탑
{
	if (n == 1) {
		move(from, to); //1->3
		return;
	}

	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
	hanoi(3,1,2,3);

	return 0;
}