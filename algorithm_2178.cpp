#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maze[100][100] = { 0 };
bool check[100][100];
int squareCnt[100][100] = { 0 };
int N, M;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y) {
	check[x][y] = true;
	squareCnt[x][y]++;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !check[nx][ny] && maze[nx][ny] == 1) {
				check[nx][ny] = true;
				q.push({ nx, ny });
				squareCnt[nx][ny] = squareCnt[xx][yy]+1;
			}
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	bfs(0, 0);

	cout << squareCnt[N - 1][M - 1];
	
	return 0;
}