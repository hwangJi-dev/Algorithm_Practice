#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
 
int main() {
    // 초기값  
    vector<int> smallPeople;
    vector<int> answerVector;
    for (int i = 0; i < 9; i++) {
        int sub;
        cin >> sub;
        smallPeople.push_back(sub);
    }
 
    int isComplete = 0;
 
    for (int i = 0; i < 9 && (isComplete == 0) ; i++) {
        for (int j = i+1; j < 9 && (isComplete == 0); j++) {
            int sum = 0;
            answerVector.clear();
            for (int l = 0; l < 9; l++) {
                if ((l != i) && (l != j)) {
                    answerVector.push_back(smallPeople[l]);
                    sum += smallPeople[l]; 
                }
            }
            if (sum == 100) isComplete = 1;
        }
    }
 
    sort(answerVector.begin(), answerVector.end());
    for (int i = 0; i < 7; i++)
        cout << answerVector[i] << "\n";
 
    return 0; 
}
