#include <iostream>
#include <queue>

using namespace std;

int to[1002][1002]{};
int visit[1002][1002]{};
int ans = 0;
int vcount = 0;
queue<pair<int, int>> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int m, n;

	cin >> m >> n;

	for (int i = 0; i < 1002; i++) // �� ���� �� ä���� �� ��
		for (int j = 0; j < 1002; j++)
			if (j == 0 || j > m || i == 0 || i > n)
				visit[i][j] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> to[i][j];
			if (to[i][j] == 1)
			{
				q.push({ i, j }); // ������ �ֱ�
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;

		//visit[a][b] = 1; 
		to[a][b] = 1;
		//cout << a << ' ' << b << '\n';

		q.pop();

		// ���� �丶�� �� 0�̰�, �湮 ���ߴ� �͸� ��
		if (to[a][b - 1] == 0 && !visit[a][b - 1])
		{
			q.push({ a,b - 1 });
			visit[a][b - 1] = visit[a][b] + 1;
		}
		if (to[a + 1][b] == 0 && !visit[a + 1][b])
		{
			q.push({ a + 1,b });
			visit[a + 1][b] = visit[a][b] + 1;
		}
		if (to[a][b + 1] == 0 && !visit[a][b + 1])
		{
			q.push({ a,b + 1 });
			visit[a][b + 1] = visit[a][b] + 1;
		}
		if (to[a - 1][b] == 0 && !visit[a - 1][b])
		{
			q.push({ a - 1,b });
			visit[a - 1][b] = visit[a][b] + 1;
		}
	}



	int max = 0;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
		{
			if (!visit[i][j] && !to[i][j])
			{
				cout << -1;
				return 0;
			}
			if (visit[i][j] > max)
				max = visit[i][j];
		}
	cout << max - 1;
	return 0;
}