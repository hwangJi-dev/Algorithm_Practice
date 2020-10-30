#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> unknownPerson;
vector<string> answerList;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    unknownPerson.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> unknownPerson[i];
    }

    sort(unknownPerson.begin(), unknownPerson.end());

    string str;
    for (int i = 0; i < M; i++) {
        cin >> str;

        if (binary_search(unknownPerson.begin(), unknownPerson.end(), str)) {
            answerList.push_back(str);
        }
    }

    int answer_size = answerList.size();

    sort(answerList.begin(), answerList.end());

    cout << answer_size << '\n';

    for (int i = 0; i < answer_size; i++) {
        cout << answerList[i] << '\n';
    }

    return 0;
}