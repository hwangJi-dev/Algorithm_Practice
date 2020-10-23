#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SIZE 100


char board[MAX_SIZE + 1][MAX_SIZE + 1];
int number;

int checkCandy();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> number;
	int result = 0; 
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			cin >> board[i][j];
		}
	}
	// 입력 완료

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number - 1; j++)
		{
			// 좌우 바꾸기
			swap(board[i][j], board[i][j + 1]);
			result = max(result, checkCandy());
			swap(board[i][j], board[i][j + 1]);
			// 상하 바꾸기
			swap(board[j][i], board[j + 1][i]);
			result = max(result, checkCandy());
			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << result << "\n";

}

int checkCandy()
{
	int curMax = 1; // 현재 최대값, 초기값은 1 (인접한 색의 캔디가 하나도 없을 경우)
	// 좌우체크
	for (int i = 0; i < number; i++)
	{
		int temp = 1;
		for (int j = 0; j < number - 1; j++)
		{
			if (board[i][j] == board[i][j + 1]) // 좌우가 같다면
			{
				temp++; // 현재까지 연속하는 사탕의 갯수 1 누적
			}
			else
			{
				curMax = max(curMax, temp);
				// 현재까지 연속했던 사탕의 갯수가 현재까지의 최대값보다 크다면 갱신
				temp = 1;
			}
		}
		curMax = max(curMax, temp);
		// for-j문의 마지막 if문이 true였다면 curMax가 갱신되지 않았을 것이므로
		// 마지막 갱신 후 다음 for-i문으로 넘어감
	}

	// 상하체크
	for (int i = 0; i < number; i++)
	{
		int temp = 1;
		for (int j = 0; j < number - 1; j++)
		{
			if (board[j][i] == board[j + 1][i]) // 상하가 같다면
			{
				temp++; // 현재까지 연속하는 사탕의 갯수 1 누적
			}
			else
			{
				curMax = max(curMax, temp);
				// 현재까지 연속했던 사탕의 갯수가 현재까지의 최대값보다 크다면 갱신
				temp = 1;
			}
		}
		curMax = max(curMax, temp);
		// for-j문의 마지막 if문이 true였다면 curMax가 갱신되지 않았을 것이므로
		// 마지막 갱신 후 다음 for-i문으로 넘어감
	}

	return curMax;

}