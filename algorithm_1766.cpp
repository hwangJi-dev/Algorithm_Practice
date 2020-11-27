#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 32001;
int N,M;
vector<int> graph[MAX];
int numPredecessor[MAX];
 
void bfs(){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1; i<=N; i++){
        if(numPredecessor[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        cout<<cur<<" ";
        for(int i=0; i<graph[cur].size(); i++){
            numPredecessor[graph[cur][i]]--;
            if(numPredecessor[graph[cur][i]]==0)
                q.push(graph[cur][i]);
        }
    }
}
 
int main(void){
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        numPredecessor[b]++;
    }
    bfs();
}