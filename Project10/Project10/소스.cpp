#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int map[4][3] = {
		3,5,1,
		3,1,2,
		3,4,6,
		5,4,6 };

	int bucket[7] = { 0 };

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			bucket[map[y][x]]++;
		}
	}

	for (int x = 1; x < 7; x++)
	{
		cout << x<<" ";
		for (int y = 1; y <= bucket[x]; y++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}