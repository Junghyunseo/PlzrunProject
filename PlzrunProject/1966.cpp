#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);


	int t, N, M;
	int arr[11]{};
	queue<pair<int, int>> q;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int ans = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp; // tmp: �߿䵵
			arr[tmp]++; // �ش� �߿䵵�� ���� ����
			if (j == M) // �ñ��� ������ second: 1
			{
				q.push({ tmp,1 });
			}
			else // �ٸ� ������ second: 0
				q.push({ tmp,0 });
		}

		while (!q.empty())
		{
			int a = q.front().first; // �߿䵵
			int b = q.front().second; // �ñ��� ��������

			int cnt = 0;
			for (int j = 1; a + j < 10; j++)
			{
				if (!arr[a + j]) // �ڿ� �߿䵵�� ������ ������
					cnt++;
			}
			if (cnt == 9 - a) // �ڿ� �� ���� �� �߿䵵�� �� ������ �ϳ��� ������ ������ or ����ϱ�
			{
				arr[a]--; // �̰� �߿䵵 �����
				ans++;
				if (b == 1) // �˰�����Ÿ�
				{
					cout << ans << '\n';
					q.pop();
				}
				else
					q.pop(); // ������
			}
			else // �ھ� �� ���� �� �߿䵵�� ������ �ϳ��� ������ �� �ڷ� ������
			{
				q.push({ a,b });
				q.pop();
			}
		}

	}

	return 0;
}