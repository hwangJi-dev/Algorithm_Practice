#include <iostream>
using namespace std;

#define MAX_SIZE 50

int main(){

    //입력 데이터의 수를 나타내는 변수
    int testCase;
    int i,j,length,count;

    cin >> testCase;
    char arr[MAX_SIZE];

    for (i = 0 ; i < testCase ; i++){
        count = 0;
        cin >> arr ;

        for (j=0; j< MAX_SIZE; j++){

            if (arr[j] == '\0'){
                break;
            }

            if (arr[j] == '('){
                count++ ;
            }

            else if (arr[j] == ')' && count > 0){
                count--;
            }
            else if (arr[j] == ')' && count <=0 ){
                count--;

                break;
            }
            
        }

        if (count == 0){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    
    }

    return 0;

}