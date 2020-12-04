#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int N;
int result;
map<char, int> words;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cur = 1;
		for (int j = str.size() - 1; j >= 0; j--) {
			words[str[j]] += cur;
			cur *= 10;
		}
	}
	priority_queue<int> q;
	map<char, int>::iterator iter;
	for (iter = words.begin(); iter != words.end(); iter++)
		q.push(iter->second);

	int count = 9;
	while (!q.empty()) {
		result += q.top() * count;
		q.pop();
		count--;
	}
	
	cout << result;
}