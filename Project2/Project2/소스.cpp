#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int door[5];
	int cnt;
	int level;
}

int main()
{
	int door[5];

	for (int x = 0; x < 5; x++)
	{
		cin >> door[x];
	}

	int guest[12] = { 0,1,0,1,0,1,2,3,2,3,2,3 };
	int minn = 99;
	int direct[2] = { -1,1 };

	Node t[50];

	for (int x = 0; x < 5; x++)
	{
		t[0].door[x] = door[x];
	}

	t[0].level = 0;
	t[0].cnt = 0;

	int head = 0;
	int tail = 1;
	int cnt = 0;

	while (head != tail)
	{
		Node now = t[head];
		cnt = 0;

		int yy=99;
		int yyy=99;

		if (now.level >= 12) break;
		if (now.level == 11) { if (minn > now.cnt) minn = now.cnt; }

		if (now.door[guest[now.level]] == 1) //이동할 곳에 문이 있다
		{
			for (int y = 0; y < 2; y++)
			{
				yy = direct[y] + guest[now.level];
				if (yy >= 0 && yy < 5) //이동하고 싶은 곳에 있는 문을 맵 내 오른쪽 혹은 왼쪽으로 치운다
				{
					if (now.door[guest[yy]] == 1) //이동하고 싶은 곳을 치울 만한 곳에 문이 또 있다
					{
						yyy = yy;
						while (now.door[guest[yyy]] != 0) //0이 나올때까지 계속 이동
						{
							yyy += direct[y];
							cnt++;
						}
					}

					else if (guest[yy] == 0) cnt++;//이동하고 싶은 곳을 치울 만한 곳에 문이 없다=이동가능
				}
			}


			t[tail].level = now.level + 1; //다음 손님 부름
			t[tail].cnt = now.cnt + cnt;

			for (int x = 0; x < 5; x++)
			{
				if (x == yy || x == yyy) {
					t[tail].door[yy] = 0;
					t[tail].door[yyy] = 1;
				}
				t[tail].door[x] = now.door[x];
			}
			tail++;
		}
		head++;
	}

	cout << minn;

	return 0;
}