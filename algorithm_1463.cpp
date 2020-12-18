#include <iostream>
#include <algorithm>

using namespace std;
int integer[1000001];

int solution(int n)
{
	for (int i = 2; i <= n; i++)
	{
		integer[i] = integer[i - 1] + 1;
		if (i % 2 == 0)
			integer[i] = min(integer[i / 2] + 1, integer[i]);
		if (i % 3 == 0)
			integer[i] = min(integer[i / 3] + 1, integer[i]);
	}

	return integer[n];

}
int main()
{
	integer[1] = 0;
	int n;
	cin >> n;

	cout << solution(n);
}