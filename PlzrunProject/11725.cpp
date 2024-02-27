#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(100002);
int parent[100002]{};

void dfs(int num)
{
	while (!v[num].empty()) // ������� ������
	{
		int toVisit = v[num].back(); // �湮�� ��� ��ȣ
		if (!parent[toVisit]) // �θ� ���ٸ�
			parent[toVisit] = num; // �θ� ǥ��

		v[num].pop_back();
		if (!v[toVisit].empty()) // �湮�� ���� ������� ������
			dfs(toVisit);
	}
	// ���⿡�� v ������ ���ҿ� ��� �����߾��� -> v�� ��������� �翬�� �� ��
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