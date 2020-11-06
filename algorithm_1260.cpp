#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> vec[1001];   
bool check[1001];        
void dfs(int x);
void bfs(int x);
int N, M, startVnum;

int main()
{

    cin >> N >> M >> startVnum;

    while(M--){
        int a, b;
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(vec[i].begin(), vec[i].end());

    dfs(startVnum);
    cout << "\n";
    
    memset(check, false, sizeof(check));
    
    bfs(startVnum);
    cout << "\n";
}

void dfs(int x){
    cout << x << " ";
    check[x] = true;

    for (int i = 0; i < vec[x].size(); i++){
        int y = vec[x][i];
        if (check[y] == false)
            dfs(y);
    }
}

void bfs(int x){
    queue<int> q;

    q.push(x);
    check[x] = true;

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int i = 0; i < vec[currentNode].size(); i++){
            int y = vec[currentNode][i];
            if(check[y] == false){
                q.push(y);
                check[y] = true;
            }
        }
    }
}