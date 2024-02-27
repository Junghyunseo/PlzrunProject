#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int graph[1001][1001]{}; // ���� ���� ����
int visit[1001]{}; // �湮 ����

void dfs(int num)
{
	for (int i = 1; i < 1001; i++)
	{
		if (graph[num][i] && !visit[i])
		{
			visit[i] = 1; // �湮������ üũ
			cout << i << ' ';
			dfs(i);
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m, v;
	queue<int> q;

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1; // ��������� ���� ���� ����
		graph[b][a] = 1;
	}
	visit[v] = 1; // ù ���� �湮 ǥ��
	cout << v << ' '; // ù ���� ���
	dfs(v);

	fill(visit, visit + 1001, 0); // �湮 ���� �ʱ�ȭ

	cout << '\n';

	cout << v << ' ';
	q.push(v);
	visit[v] = 1;

	while (!q.empty())
	{
		for (int i = 1; i < 1001; i++)
		{
			if (graph[q.front()][i] && !visit[i])
			{
				visit[i] = 1;
				q.push(i);
				cout << i << ' ';
			}
		}
		q.pop();
	}

	return 0;
}