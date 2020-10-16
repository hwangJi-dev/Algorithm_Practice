#include <iostream>
#include <queue>
using namespace std;

int main(){

    int tastCase;
    cin >> tastCase;
    int count = 0;
    int docCnt,curiousDoc,importantRatio;

    for (int i=0;i<tastCase;i++){

        count = 0; //이거 제일 중요..... 별꼬리용용..... 아.......우와.....

        //문서의 개수, 궁금한 문서의 위치 입력받기
        cin >> docCnt >> curiousDoc;

        queue<pair<int, int>> Q;
        priority_queue<int> priorityQ;

        for (int j=0 ; j<docCnt; j++){
            cin >> importantRatio;
            Q.push({j,importantRatio});
            priorityQ.push(importantRatio);
        }
        
        while(!Q.empty()){
            int nowIndex = Q.front().first; //말그대로 인덱스
            int importantRatioValue = Q.front().second; //importantRatioValue
            Q.pop();
            if (priorityQ.top() == importantRatioValue) {
                priorityQ.pop();
                count++;
                if (nowIndex == curiousDoc){
                    cout << count << endl;
                    break;
                }
            }
            else {
                Q.push({nowIndex,importantRatioValue});
            }
        }
    }
    return 0;
}