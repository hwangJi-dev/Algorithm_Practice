#include <iostream>
#include <algorithm>
using namespace std;
int home[1001][3];
int main() {
    int paintCost[3];
    int N;

    home[0][0] = 0;
    home[0][1] = 0;
    home[0][2] = 0;

    cin >> N;

    for(int i = 1; i <= N; ++i)
    {
        cin >> paintCost[0] >> paintCost[1] >> paintCost[2];
        home[i][0] = min(home[i-1][1],home[i-1][2]) + paintCost[0];
        home[i][1] = min(home[i-1][0],home[i-1][2]) + paintCost[1];
        home[i][2] = min(home[i-1][1],home[i-1][0]) + paintCost[2];
    }

    cout << min(home[N][2],min(home[N][0],home[N][1]));
}