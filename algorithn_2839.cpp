#include<iostream>
using namespace std;
int main() {
	int N, max, mod, result;
	cin >> N;
	max = N / 5; 
	while (max >= 0) {
		mod = 0;
		result = 0;
		if (max > 0)
		{
			mod = N - 5 * max; 
			result = max;
		}
		else
			mod = N;
		result += mod / 3; 
		mod = mod % 3; 
		
		if (mod == 0)
		{
			cout << result;
			break;
		}
        max--; 
	}
	if (mod != 0)
		cout << -1;
}