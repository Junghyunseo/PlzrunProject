#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int >> V(1001);
int visit[1001]{};


void dfs(int num)
{
	for (int i = 0; i < V[num].size(); i++)
	{
		if (!visit[V[num][i]])
		{
			visit[V[num][i]] = 1;
			dfs(V[num][i]);
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	int ans = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++)
		sort(V[i].begin(), V[i].end());

	for (int i = 1; i < n + 1; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}