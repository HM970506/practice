#include <iostream>
#include <string.h>
using namespace std;

char map1[4][5];
char map2[4][5];

void backup(char a[4][5], char b[4][5]) //
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			a[y][x] = b[y][x];
		}
	}
}

void turn(int y, int x)
{
	int where[8][2] = {
		0,1,
		0,-1,
		1,0,
		-1,0,
		1,1,
		1,-1,
		-1,1,
		-1,- 1 };

	for (int z = 0; z < 8; z++)
	{
		int yy = y + where[z][0];
		int xx = x + where[z][1];

		if (yy >= 0 && xx >= 0 && yy < 4 && xx < 4)
		{
			map2[y][x] = map1[x][4 - y];
		}
	}
	backup(map1, map2);
}

int AAA()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			if (map1[y][x] == 'A' && map1[y][x + 1] == 'A' && map1[y][x + 2] == 'A')
				return 1;
		}
	}
	return 0;
			
}
int flag = 0;
void run(int r)
{
	if (r >= 7) return; //6회까지만 가능

	if (AAA() == 1)//AAA가 존재하면 flag=1로 두고 리턴
	{
		flag = 1;
		return;
	}
	for (int y = 1; y < 3; y++)
	{
		for (int x = 1; x < 3; x++)
		{
			turn(y, x);
			run(r + 1);
			turn(y, x);
			turn(y, x);
			turn(y, x);
		}
	}
}

int main()
{
	for (int y = 0; y < 4; y++)
	{
		cin >> map1[y];
	}
	backup(map2, map1);

	run(0);

	if (flag == 1) cout << "가능";
	else cout << "불가능";

	return 0;
}