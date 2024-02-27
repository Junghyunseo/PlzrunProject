#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> V(20001);
int visit[20001]; // 방문 여부 저장
int EO[20001]{}; // 홀짝: 집합 그룹 0:홀수 1: 짝수
int ans = 1;
int num = 0;

void dfs(int n)
{
	for (int i = 0; i < V[n].size(); i++)
	{
		if (!visit[V[n][i]]) // 방문 안 한 정점일 경우 방문
		{
			visit[V[n][i]] = 1; // 방문 표시
			// 집합 그룹을 무조건 부른 것과 불러진 것은 반대로 배분
			if (EO[n])
				EO[V[n][i]] = 0;
			else
				EO[V[n][i]] = 1;
			dfs(V[n][i]);
		}
		else // 방문했던 정점일 경우
			if (EO[n] == EO[V[n][i]]) // 그 정점과 그 전 정점이 같은 집합에 있으면 NO
				ans = 0;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int k, v, e;

	cin >> k;

	for (int i = 0; i < k; i++) // k번 반복
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
		//ans 초기화
		ans = 1;
		// visit 초기화
		fill(visit, visit + 20001, 0);
		// EO 초기화
		fill(EO, EO + 20001, 0);
		// 벡터 초기화
		for (int i = 0; i < V.size(); i++)
		{
			while (!V[i].empty())
				V[i].pop_back();
		}
	}

	return 0;
}