#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	char arr[50][50];
	int BWMinCost = 52;
	int WBMinCost = 52;
	queue<pair<int, int>> q;

	char BW[8][8];
	char WB[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (!(i % 2) && !(j % 2) || (i % 2) && (j % 2))
			{
				BW[i][j] = 'B';
				WB[i][j] = 'W';
			}
			else
			{
				BW[i][j] = 'W';
				WB[i][j] = 'B';
			}
		}
	}
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
			q.push({ i,j });
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int BWTempMin = 0;
		int WBTempMin = 0;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[x + i][y + j] != BW[i][j])
					BWTempMin++;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[x + i][y + j] != WB[i][j])
					WBTempMin++;
			}
		}

		if (BWMinCost > BWTempMin)
			BWMinCost = BWTempMin;
			
		if (WBMinCost > WBTempMin)
			WBMinCost = WBTempMin;
	}

	if (BWMinCost < WBMinCost)
		cout << BWMinCost;
	else
		cout << WBMinCost;

	return 0;
}