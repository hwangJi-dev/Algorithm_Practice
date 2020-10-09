#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int testCase,studentNum,i,j;
    int sum,num = 0;
    double avg,studentRatio = 0;
  
    cin >> testCase;
   
    for (i = 0; i < testCase; i++) {
        cin >> studentNum;
        int scoreArray[studentNum];
        
        for (j=0; j< studentNum; j++){
            cin >> scoreArray[j];
            sum += scoreArray[j];
        }
        avg = double(sum) / studentNum;
        
        for (j=0; j< studentNum; j++){
            if (avg < scoreArray[j]) {
                num++;
            }
        }
       studentRatio = ((double)num / studentNum)*100; 
        cout.precision(3); 
        cout << fixed << studentRatio << "%"<< endl; 
        sum = 0, avg = 0, studentRatio = 0, num = 0;
    }
    return 0;
}
ㄴ