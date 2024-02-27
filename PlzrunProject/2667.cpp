#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[27][27]{};
int visit[27][27]{};
int house = 0;
int dan = 0;
vector<int> v;

void dfs(int a, int b)
{
	visit[a][b] = 1; // �湮 ǥ��

	//if (arr[a][b]) // �� ���� ����
	house++;

	if ((!visit[a][b - 1]) && arr[a][b - 1])
		dfs(a, b - 1);
	if ((!visit[a + 1][b]) && arr[a + 1][b])
		dfs(a + 1, b);
	if ((!visit[a][b + 1]) && arr[a][b + 1])
		dfs(a, b + 1);
	if ((!visit[a - 1][b]) && arr[a - 1][b])
		dfs(a - 1, b);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	char c;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	for (int i = n + 1; i < 27; i++) // �׵θ� �� �湮�� ������ ����
		for (int j = n + 1; j < 27; j++)
			visit[i][j] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (!visit[i][j] && arr[i][j])
			{
				dan++; // ���� �� ����
				dfs(i, j);
			}

			if (house)
				v.push_back(house);

			// �ʱ�ȭ
			house = 0;
		}
	}

	sort(v.begin(), v.end());

	cout << dan << '\n';

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	if (v.empty())
		cout << 0;

	return 0;
}