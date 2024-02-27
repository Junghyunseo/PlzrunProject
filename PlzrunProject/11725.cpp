#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(100002);
int parent[100002]{};

void dfs(int num)
{
	while (!v[num].empty()) // 비어있지 않으면
	{
		int toVisit = v[num].back(); // 방문할 노드 번호
		if (!parent[toVisit]) // 부모가 없다면
			parent[toVisit] = num; // 부모 표시

		v[num].pop_back();
		if (!v[toVisit].empty()) // 방문할 곳이 비어있지 않으면
			dfs(toVisit);
	}
	// 여기에서 v 마지막 원소에 계속 접근했었음 -> v가 비어있으면 당연히 안 됨
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	parent[1] = 1e9;
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i < n + 1; i++)
		cout << parent[i] << '\n';

	return 0;
}