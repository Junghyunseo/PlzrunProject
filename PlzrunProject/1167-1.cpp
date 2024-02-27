#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> tree(100002);
vector<vector<pair<int, int>>> copyTree(100002);
int dis[100002]{};
int maxIndex = 1;

void dfs(int num)
{
	while (!tree[num].empty()) // 방문한 노드가 비어있지 않으면
	{
		int toVisit = tree[num].back().first; // 방문할 노드 번호
		int between = tree[num].back().second; // num 노드와 방문할 노드 사이의 거리

		if (!dis[toVisit] && (toVisit != maxIndex) && (toVisit != num)) // num에서 방문할 노드까지의 거리 업데이트
			dis[toVisit] += dis[num] + between;
		dis[maxIndex] = 0;
		//cout << toVisit << ' ' << between << ' ' << "dis: " << dis[toVisit] << '\n';
		tree[num].pop_back();
		dfs(toVisit);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int v;
	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int node, a, b;
		cin >> node; // 정점 번호
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			tree[node].push_back({ a, b }); // node와 a가 연결되어 있고, 거리가 b
		}
	}
	// 트리 복사
	copyTree.resize(tree.size());
	copy(tree.begin(), tree.end(), copyTree.begin());

	int max = 0;
	dfs(1);

	for (int i = 1; i < v + 1; i++)
		if (max < dis[i])
		{
			max = dis[i];
			maxIndex = i;
		}
	copy(copyTree.begin(), copyTree.end(), tree.begin()); // 트리 돌려놓기
	fill(dis, dis + 100002, 0); // dis 초기화

	//cout<< maxIndex<<"!@#$!@3"<<'\n';
	dfs(maxIndex);

	for (int i = 1; i < v + 1; i++)
		if (max < dis[i])
			max = dis[i];

	cout << max;


	return 0;
}