#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string bucket;
	int input[5] = { 0 };

	for (int x = 0; x < n; x++)
	{
		cin >> input[x];
		if (bucket[input[x]] == 1) bucket[input[x]]++;
		else bucket[input[x]] = 1;;
	}

	int sum = 0;

	int len = bucket.length();

	for (int x = 1; x < len ; x++)
	{
		bucket[x] += bucket[x-1];
		cout << bucket[x];
	}


	cout << endl;

	int result[5];

	for (int x = 0; x < 5; x++)
	{
		result[bucket[input[x]] - 1] = input[x];
	}

	for (int x = 0; x < 5; x++)
	{
		cout << result[x];
	}

	return 0;
}