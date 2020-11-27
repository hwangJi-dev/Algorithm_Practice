#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > p_queue;
    while (n--) {
        int num;
        cin >> num;
        p_queue.push(num);
    }
    int compareCnt = 0;
    while (p_queue.size() != 1) {
        int a = p_queue.top();
        p_queue.pop();
        int b = p_queue.top();
        p_queue.pop();
        compareCnt += a + b;
        p_queue.push(a + b);
    }
    cout << compareCnt;
 
    return 0;
}