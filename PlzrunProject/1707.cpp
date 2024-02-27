#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> V(20001);
int visit[20001]; // �湮 ���� ����
int EO[20001]{}; // Ȧ¦: ���� �׷� 0:Ȧ�� 1: ¦��
int ans = 1;
int num = 0;

void dfs(int n)
{
	for (int i = 0; i < V[n].size(); i++)
	{
		if (!visit[V[n][i]]) // �湮 �� �� ������ ��� �湮
		{
			visit[V[n][i]] = 1; // �湮 ǥ��
			// ���� �׷��� ������ �θ� �Ͱ� �ҷ��� ���� �ݴ�� ���
			if (EO[n])
				EO[V[n][i]] = 0;
			else
				EO[V[n][i]] = 1;
			dfs(V[n][i]);
		}
		else // �湮�ߴ� ������ ���
			if (EO[n] == EO[V[n][i]]) // �� ������ �� �� ������ ���� ���տ� ������ NO
				ans = 0;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int k, v, e;

	cin >> k;

	for (int i = 0; i < k; i++) // k�� �ݺ�
	{
		cin >> v >> e;
		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;

			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (int j = 1; j < v + 1; j++)
			sort(V[j].begin(), V[j].end());

		for (int j = 1; j < v + 1; j++)
		{
			if (!visit[j])
			{
				visit[j] = 1;
				dfs(j);
			}
		}
		if (!ans)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		//ans �ʱ�ȭ
		ans = 1;
		// visit �ʱ�ȭ
		fill(visit, visit + 20001, 0);
		// EO �ʱ�ȭ
		fill(EO, EO + 20001, 0);
		// ���� �ʱ�ȭ
		for (int i = 0; i < V.size(); i++)
		{
			while (!V[i].empty())
				V[i].pop_back();
		}
	}

	return 0;
}