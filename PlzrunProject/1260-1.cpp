#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

//int graph[1001][1001]{}; // ���� ���� ����

//vector<int> V[1001]{}; ����
vector<vector<int>> V(1001);

int visit[1001]{}; // �湮 ����

void dfs(int num)
{
	for (int i = 0; i < V[num].size(); i++)
	{
		if (!visit[V[num][i]])
		{
			visit[V[num][i]] = 1; // �湮������ üũ
			cout << V[num][i] << ' ';
			dfs(V[num][i]);
		}
	}
	/*for (int i : V[num])
	{
		if (!visit[i])
		{
			visit[i] = 1; // �湮������ üũ
			cout << i << ' ';
			dfs(i);
		}
	}*/
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
		V[a].push_back(b); // ��������� ���� ���� ����
		V[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++)
		sort(V[i].begin(), V[i].end());
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
		for (int i = 0; i < V[q.front()].size(); i++)
		{
			if (!visit[V[q.front()][i]])
			{
				visit[V[q.front()][i]] = 1;
				q.push(V[q.front()][i]);
				cout << V[q.front()][i] << ' ';
			}
		}
		q.pop();
	}

	return 0;
}