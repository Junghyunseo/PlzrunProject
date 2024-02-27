#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> v(10002);
int visited[10002]{};
int Max = 0;
int maxIndex = 0;

void dfs(int num, int dist)
{
	if (visited[num]) // �湮�ߴ� �� ��湮 �� ��
		return;
	if (Max < dist) // �� ū �Ÿ� ������Ʈ
	{
		Max = dist;
		maxIndex = num;
	}

	visited[num] = 1; // �湮 ǥ��

	for (int i = 0; i < v[num].size(); i++)
	{
		int toVisit = v[num][i].first;
		int between = v[num][i].second;
		//cout << toVisit << ' ' << between << ' ' << Max << '\n';
		dfs(toVisit, between + dist);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio();
	int n;
	cin >> n;

	int p, c, d;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> p >> c >> d;
		v[p].push_back({ c,d });
		v[c].push_back({ p,d });
	}

	dfs(1, 0);

	fill(visited, visited + 10002, 0);
	Max = 0;

	dfs(maxIndex, 0);

	cout << Max;

	return 0;
}