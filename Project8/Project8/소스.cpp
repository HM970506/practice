#include <iostream>
using namespace std;

int main()
{
	int queue[100];
	queue[0] = 1;

	int head = 0;
	int tail = 1;

	int n;
	cin >> n;

	int sum = queue[0];

	for(int x=0; x<n; x++){
		queue[tail] = queue[head] * 3;
		sum += queue[tail];
		tail++;
		head++;

	}

	cout << sum;


	return 0;
}