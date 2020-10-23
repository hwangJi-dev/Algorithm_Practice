#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int number = 1000001;
int breakBtn[10]; //1일 때 ; 고장난 버튼

//누를 수 있는 번호인지
bool isPossibleNum(int num) {
	if (num == 0) {
		if (breakBtn[0] == 1)
			return false;
		else
			return true;
	}
	while (num) {
		if (breakBtn[num % 10] == 1) {
			return false;
		}
		num /= 10;
	}
	return true;
}

int getMin(int num) {
	int From100 = abs(num - 100);
	int Min = number;
	int tmp;
	for (int i = 0; i <= number; i++) {
		if (isPossibleNum(i)) {
			tmp = to_string(i).length();
			tmp += abs(i - num);
			Min = min(Min, tmp);
		}
	}
	return min(From100, Min);
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		breakBtn[n] = 1;
	}
	cout << getMin(N) << endl;
	return 0;
}