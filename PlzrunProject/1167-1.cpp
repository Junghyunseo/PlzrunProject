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
	while (!tree[num].empty()) // �湮�� ��尡 ������� ������
	{
		int toVisit = tree[num].back().first; // �湮�� ��� ��ȣ
		int between = tree[num].back().second; // num ���� �湮�� ��� ������ �Ÿ�

		if (!dis[toVisit] && (toVisit != maxIndex) && (toVisit != num)) // num���� �湮�� �������� �Ÿ� ������Ʈ
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
		cin >> node; // ���� ��ȣ
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			tree[node].push_back({ a, b }); // node�� a�� ����Ǿ� �ְ�, �Ÿ��� b
		}
	}
	// Ʈ�� ����
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
	copy(copyTree.begin(), copyTree.end(), tree.begin()); // Ʈ�� ��������
	fill(dis, dis + 100002, 0); // dis �ʱ�ȭ

	//cout<< maxIndex<<"!@#$!@3"<<'\n';
	dfs(maxIndex);

	for (int i = 1; i < v + 1; i++)
		if (max < dis[i])
			max = dis[i];

	cout << max;


	return 0;
}