#include<iostream>

using namespace std;

int main()
{
	long long S;
	cin >> S;

	long long x = 0;
	long long max = 1;
	while (x < S)
	{
		x = x + max;
		max++;
	}

	if (x == S)
	{
		cout << max - 1 << endl;
	}
	else {
		cout << max - 2 << endl;
	}
}