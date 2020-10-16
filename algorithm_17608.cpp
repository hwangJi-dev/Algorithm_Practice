#include <iostream>
using namespace std;

#define MAX_SIZE 50

int main(){


    //barArray를 100001번방까지 만들어주는 이유는, 
    //문제에서 첫번 째 줄에는 막대기의 개수를 나타내는 정수가 100,000개까지 주어진다고 했기 때문이다. 
    //막대기의 개수를 나타내는 정수인 첫번째 줄을 제외하고 100,000개의 입력이 생길 수 있으니 100,000 + 1 => 100,001만큼의 크기를 가진 배열을 만들어줘야 한다.
    int inputSize,count = 0,maxIndex = 0,barArray[100001];

    cin >> inputSize;


    for (int i=0;i<inputSize;i++){
        cin >> barArray[i];
    }
    
   
    for(int j = inputSize-1;j>=0;j--){

        if (barArray[j] > maxIndex){
            maxIndex = barArray[j];
            count++;
        }
    }

    cout<<count;

    return 0;

}