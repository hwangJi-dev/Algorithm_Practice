#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000000001;
int N;
vector<int> v;

int main(void)

{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N;
    v.resize(N);
    
     for (int i = 0; i < N; i++) {
         
         cin >> v[i];
         sort(v.begin(), v.end());
         
         if (v[0] != 1) {
             cout << 1 << "\n";
        }
         else {
          int sum = 1; 

          for (int i = 1; i < N; i++) {
              
              if (v[i] > sum + 1)
              break;
              sum += v[i];      
        }
        cout << sum + 1 << "\n";
        }
     }
     return 0;
}
