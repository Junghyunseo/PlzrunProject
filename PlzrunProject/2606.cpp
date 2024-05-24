#include<iostream>

using namespace std;

int arr[101][101]{};
int visit[101][101]{};
int ansArr[101]{};
int N, M;

void dfs(int num)
{
	for (int i = 1; i < N + 1; i++)
		if (arr[num][i] && num != i && !visit[num][i])
		{
			//cout << num << ' ' << i << '\n';
			visit[num][i] = 1;
			visit[i][num] = 1;
			ansArr[i] = 1;
			ansArr[num] = 1;
			dfs(i);
		}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(1);
	int realAns = 0;
	for (int i = 0; i < 101; i++)
		if (ansArr[i])
			realAns++;
	if (realAns)
		cout << realAns - 1;
	else
		cout << 0;
	return 0;
}