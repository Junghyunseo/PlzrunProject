
// 시간 초과 // 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> tree(100002);
vector<vector<pair<int, int>>> copyTree(100002);
int dis[100002]{};
int visited[100002]{};

void dfs(int num)
{
	visited[num] = 1;
	while (!tree[num].empty()) // 방문한 노드가 비어있지 않으면
	{
		int toVisit = tree[num].back().first; // 방문할 노드 번호
		int between = tree[num].back().second; // num 노드와 방문할 노드 사이의 거리

		if (!dis[toVisit] && (toVisit != num)) // num에서 방문할 노드까지의 거리 업데이트
			dis[toVisit] += dis[num] + between;

		cout << toVisit << ' ' << between << ' ' << "dis: " << dis[toVisit] << '\n';


		tree[num].pop_back();
		if (!visited[toVisit])
			dfs(toVisit);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int v;
	queue<int> q;

	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int node, a, b;
		cin >> node; // 정점 번호
		int count = 0; // 정점이 몇 개의 다른 정점과 연결되어 있는지
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			count++;
			tree[node].push_back({ a, b }); // node와 a가 연결되어 있고, 거리가 b
		}
		if (count == 1) // 트리의 끝 지점들(정점이 오직 하나의 정점과만 연결되어 있는 거)
			q.push(node);
	}


	//dfs(1);

	// 트리 복사
	copyTree.resize(tree.size());
	copy(tree.begin(), tree.end(), copyTree.begin());


	int max = 0;

	while (!q.empty()) // 트리의 끝점들만 집어넣기
	{
		cout << "끝: " << q.front() << '\n';
		dfs(q.front());
		dis[q.front()] = 0;
		q.pop();

		tree.resize(copyTree.size());
		copy(copyTree.begin(), copyTree.end(), tree.begin()); // 트리 돌려놓기

		for (int i = 1; i < v + 1; i++)
			if (max < dis[i])
				max = dis[i];

		fill(dis, dis + 100002, 0); // dis 돌려놓기
		fill(visited, visited + 100002, 0);
	}

	cout << max;


	return 0;
}