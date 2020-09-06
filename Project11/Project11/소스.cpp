#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	string input;
	cin >> input;

	int cnt = 0;

	for (int x = 0; x < input.length(); x++)
	{
		if (input[x] >= 'A' && input[x] <= 'Z') input[x] += 32;

		string http = input.substr(x, 7);
		string https = input.substr(x, 8);

		if (http == "http://")
		{
			for (int z = x; z < input.length(); z++)
			{
				string backup1 = input.substr(z, 7);
				string backup2 = input.substr(z, 8);
				if (backup1 != "http://") x = z + 6;
				if (backup2 != "https://")x = z + 7;

				if (x + 3 < input.length())
					for (int y = x + 3; y < input.length(); y++)
					{
						string com = input.substr(y, 4);
						string cokr = input.substr(y, 6);

						if (com == ".com" || com == ".org" || com == ".net") {
							cnt++;
							input[y] = '_';
							break;
						}
						if (cokr == ".co.kr") {
							cnt++;
							input[y] = '_';
							break;
						}
					}
			}
		}
			if (https == "https://")
			{
				for (int z = x; z < input.length(); z++)
				{
					string backup1 = input.substr(z, 7);
					string backup2 = input.substr(z, 8);
					if (backup1 != "http://") { x = z + 6; }
					if (backup2 != "https://") { x = z + 7; }

					if (x + 3 < input.length())
						for (int y = x + 3; y < input.length(); y++)
						{
							string com = input.substr(y, 4);
							string cokr = input.substr(y, 6);
							if (com == ".com" || com == ".org" || com == ".net") {
								cnt++;
								input[y] = '_';
								break;
							}
							if (cokr == ".co.kr") {
								cnt++;
								input[y] = '_';
								break;
							}
						}
				}
			}
		}
	

	cout << cnt << "°³";

	return 0;
}