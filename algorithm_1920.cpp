#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(NULL);
	
	int N, M;
	cin >> N;	
	int a[N+1];
	
	for(int i=0; i<N; i++){
		cin >> a[i];
	}
	
	sort(a, a+N);
	
	cin >> M;	
	int input[M+1];
		
	for(int i=0; i<M; i++){
		cin >> input[i];
		
		int start = 0, end = N, middle;
	
		bool check = false;
		
		while(start <= end){
			middle = (start+end)/2;
			if(input[i] < a[middle]){
				end = middle-1;
			} else if(input[i] > a[middle]) {
				start = middle + 1;
			} else {
				check = true;
				break;
			}	 
		}
		if(check) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}