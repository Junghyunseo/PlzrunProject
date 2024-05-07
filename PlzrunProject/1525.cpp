#include<iostream>
#include<queue>
using namespace std;

int arr[1000][3][3];

bool isMatchedToAnswer()
{
	return false;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int num = 1;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[0][i][j] = num++;
	arr[0][2][2] = 0;

	int x, y;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[1][i][j];
			if (arr[1][i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	int cnt = 0;
	//처음꺼 검사도 추가하기

	queue<int> q;
	q.push(1);
	int d = 2;
	while (1)
	{
		int nat = 1;
		bool isEnd = false;
		for (int i = 0; i < 4; i++) // 상하좌우 움직인 판 다 순서대로 쌓기
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 || nx < 3 || ny >= 0 || ny < 3)
				continue;
			else
			{
				//int copy = q.front();
				int copy = nat;
				q.pop();
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
						arr[copy + 1][j][k] = arr[copy][j][k];
				int tmp = arr[copy + 1][nx][ny];
				arr[copy + 1][nx][ny] = arr[d][x][y];
				arr[copy + 1][nx][ny] = tmp;

				for (int e = 1; e < d; e++)
					if (isMatchedToAnswer())
					{
						isEnd = true;
						break;
					}
						// 검사
			}
			if (isEnd)
				break;
			d++;
		}
		if (isEnd)
			break;
	}

	cout << d;

	return 0;
}