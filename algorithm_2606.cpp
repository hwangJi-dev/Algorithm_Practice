#include <iostream>
#include <vector>
using namespace std;
 
vector<int> vec[101];
int isVisit[101] = {0};
int computerCnt;
 
void dfs(int x){
    if(isVisit[x]) return;
    isVisit[x] = 1;
    computerCnt++;
    for(int i = 0; i < vec[x].size(); i++){
        int y = vec[x][i];
        dfs(y);
    }
}
 
int main(int argc, char * argv[]) {
    int N, M;
    int a, b;
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    dfs(1);
    cout << computerCnt - 1 << '\n';
    
    return 0;
}
 
