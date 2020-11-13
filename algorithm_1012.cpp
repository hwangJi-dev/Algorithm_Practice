#include <iostream>
#include <stack>
 
using namespace std;

//가로, 세로, 배추 개수
int w, h, b; 
 
// 상 하 좌 우 
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0};
 
// 배추를 심은 보드
int board[50][50];
 
// 배열 방문 여부 체크 
bool visited(int i, int j){
    if (i >=0 && i <h && j >=0 && j <w ){
        return true;

    }
    return false;
}
 
void dfs() {
    stack<pair<int, int>> st; //dfs

    int whiteWorm = 0;

    for(int i = 0; i<h ; i++){
        for(int j =0;j<w;j++){
            if (board[i][j] == 1){
                pair<int,int> pos;
                st.push(make_pair(i,j));
                board[i][j] = 0;
                while(!st.empty()){
                    int row = st.top().first; //행
                    int column = st.top().second; //열

                    for (int k = 0; k<4;k++){
                        if (visited(row + dy[k], column + dx[k]) && board[row + dy[k]][column + dx[k]] == 1) {
                            st.push(make_pair(row+dy[k], column+dx[k]));
                            board[row+dy[k]][column+dx[k]] = 0;
                            break;
                        }
                        if(k == 3){
                            st.pop();
                        }
                    }
                }
                whiteWorm ++;
        }

        }

    }
    cout<<whiteWorm<<endl;
}

 
int main() {
    int t;
 
    cin >> t;
 
    for (int i = 0; i< t; i++){
        cin>>w>>h>>b;
        for (int j = 0; j <b; j ++){
            int posX,posY;
            cin>>posX>>posY;
            board[posY][posX] = 1;
        }
        dfs();
    }
    return 0;
}