#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string n;
	cin >> n;

	int len = n.length();
	int flag = 0;

	while (1)
	{
		int x;
		for (x = 0; x < len-1; x++)
		{
			if (n[x] == '(' && n[x + 1] == '(') {
				n.erase(x + 1, 1); break;
			}
			if (n[x] == ')' && n[x + 1] == ')') {n.erase(x + 1, 1); break;
			}
			if (n[x] == '^' && n[x + 1] == '^') {n.erase(x + 1, 1); break;
			}
			if (n[x]=='^' && n[x+2]=='^')
				if (n[x + 1] != '_')
				{
					n.erase(x + 1, 1);
					n.insert(x, "_");
					break;
				}
		}
		if (x == len - 1) break;
	}

	cout << n;

	return 0;
}