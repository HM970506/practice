#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map <string, int> vect;

void init()
{
	vect["ABCDE"]=1;
	vect["BHC"]=1;
	vect["KKK"]=1;
	vect["BSS"]=1;
	vect["ABS"]=1;
}

int main()
{
	init();

	string input;
	cin >> input;

	for (int x = 0; x < 5; x++)
	{
		if (vect[input]==1) {
			cout << "O";
			return 0;
		}
	}
	cout << "X";

	return 0;
}