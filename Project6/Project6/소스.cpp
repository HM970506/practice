#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	string n;
	cin >> n;

	int x = 0;
	int y = 0;

	int cnt = 1;

	for ( x = 0; x < n.length(); x++)
	{
		if (n[x] != '_')
		{
			for (y = x+1; y < n.length(); y++)
			{
				if (n[y] == '_') break;
				
			}

			string result = n.substr(x, y-x);
			cout << cnt<<"#"<<result<<endl;
			cnt++;
			x = y;
		}
	}

	return 0;
}