#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(void)

{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int N;
        cin >> N;
        priority_queue<int> p_queue;

        for (int i = 0; i < N; i++){
            int num;
            cin >> num;
            
            if (!num && p_queue.empty())
            cout << 0 << "\n";
            
            else if (!num){
                cout << p_queue.top() << "\n";
                 p_queue.pop();
            }
            else
            p_queue.push(num);
        }

        return 0;

}