
// �ð� �ʰ� // 
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
	while (!tree[num].empty()) // �湮�� ��尡 ������� ������
	{
		int toVisit = tree[num].back().first; // �湮�� ��� ��ȣ
		int between = tree[num].back().second; // num ���� �湮�� ��� ������ �Ÿ�

		if (!dis[toVisit] && (toVisit != num)) // num���� �湮�� �������� �Ÿ� ������Ʈ
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
		cin >> node; // ���� ��ȣ
		int count = 0; // ������ �� ���� �ٸ� ������ ����Ǿ� �ִ���
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			count++;
			tree[node].push_back({ a, b }); // node�� a�� ����Ǿ� �ְ�, �Ÿ��� b
		}
		if (count == 1) // Ʈ���� �� ������(������ ���� �ϳ��� �������� ����Ǿ� �ִ� ��)
			q.push(node);
	}


	//dfs(1);

	// Ʈ�� ����
	copyTree.resize(tree.size());
	copy(tree.begin(), tree.end(), copyTree.begin());


	int max = 0;

	while (!q.empty()) // Ʈ���� �����鸸 ����ֱ�
	{
		cout << "��: " << q.front() << '\n';
		dfs(q.front());
		dis[q.front()] = 0;
		q.pop();

		tree.resize(copyTree.size());
		copy(copyTree.begin(), copyTree.end(), tree.begin()); // Ʈ�� ��������

		for (int i = 1; i < v + 1; i++)
			if (max < dis[i])
				max = dis[i];

		fill(dis, dis + 100002, 0); // dis ��������
		fill(visited, visited + 100002, 0);
	}

	cout << max;


	return 0;
}