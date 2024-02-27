#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	int map[102][102]{};
	int visit[102][102]{};
	int dis[102][102]{};
	queue<pair<int, int>> q;
	queue<pair<int, int>> gq; // �� ������ ���� �ε���

	cin >> n;

	for (int i = 0; i < 102; i++) // �׵θ��� �湮 ǥ��
		for (int j = 0; j < 102; j++)
			if (i == 0 || j == 0 || i > n || j > n)
				visit[i][j] = 1;

	for (int i = 1; i < n + 1; i++) // ���� �Է¹ޱ�
		for (int j = 1; j < n + 1; j++)
			cin >> map[i][j];

	int g = 1; // ���� ��ȣ

	// ���� ��ȣ �ο�
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (!visit[i][j] && map[i][j]) // �湮�� �� �߰�, ������ 1ǥ�� ������
			{
				q.push({ i,j }); // �� ������ ������
				gq.push({ i,j }); // ������ �����ε��� �ֱ�
				visit[i][j] = 1; // �湮 ǥ��

				while (!q.empty())
				{
					int a = q.front().first;
					int b = q.front().second;
					visit[a][b] = 1; // �湮 ǥ��
					map[a][b] = g; // ���� ��ȣ �ο�
					q.pop(); // �湮������ ����

					// �����¿�ĭ �� ���� �����ϸ� ���ÿ� �ֱ�
					if (map[a - 1][b] && !visit[a - 1][b])
					{
						q.push({ a - 1, b });
						visit[a - 1][b] = 1;
					}
					if (map[a][b + 1] && !visit[a][b + 1])
					{
						q.push({ a, b + 1 });
						visit[a][b + 1] = 1;
					}
					if (map[a + 1][b] && !visit[a + 1][b])
					{
						q.push({ a + 1, b });
						visit[a + 1][b] = 1;
					}
					if (map[a][b - 1] && !visit[a][b - 1])
					{
						q.push({ a, b - 1 });
						visit[a][b - 1] = 1;
					}
				}
				g++; // ���� ��ȣ ����
			}
		}
	}


	//while(!gq.empty())

	int min = 1e9; // �ִܰŸ�

	for (int i = 1; i < g; i++) // �� �������� �ٸ� ���������� �ִܰŸ��� ���ϱ� i: ���� ��ȣ
	{
		// visit �ʱ�ȭ
		for (int j = 1; j < n + 1; j++)
			for (int k = 1; k < n + 1; k++)
				visit[j][k] = 0;

		int a = gq.front().first; // ó���� ������ ������ �ε���
		int b = gq.front().second;
		gq.pop();


		queue<pair<int, int>> qqq;
		// �ؾȰ��� �ִ� ���� ������ queue�� �ֱ�
		for (int j = 1; j < n + 1; j++)
		{
			for (int k = 1; k < n + 1; k++)
			{
				int count = 0;
				if (map[j][k] == i)
				{
					if (map[j - 1][k] == 0 && !visit[j - 1][k])
						count++;
					if (map[j][k + 1] == 0 && !visit[j][k + 1])
						count++;
					if (map[j + 1][k] == 0 && !visit[j + 1][k])
						count++;
					if (map[j][k - 1] == 0 && !visit[j][k - 1])
						count++;

					if (count > 0)
					{
						qqq.push({ j,k });
						visit[j][k] = 1;
					}
					//else
						//dis[j][k] = -1;
				}
			}
		}

		while (1)
		{
			a = qqq.front().first;
			b = qqq.front().second;
			qqq.pop();
			//cout << a << ' ' << b << '\n';
			visit[a][b] = 1; // �湮 ǥ��


			if (!visit[a - 1][b] && map[a - 1][b] != i)
			{
				qqq.push({ a - 1,b });
				visit[a - 1][b] = 1;
				//if (map[a - 1][b] == i)
				//	dis[a - 1][b] = 0;
				if (map[a - 1][b] == 0)
					dis[a - 1][b] = dis[a][b] + 1;
				else
				{
					if (dis[a][b] < min)
						min = dis[a][b];
					break;
				}
			}
			if (!visit[a][b + 1] && map[a][b + 1] != i)
			{
				qqq.push({ a ,b + 1 });
				visit[a][b + 1] = 1;
				//if (map[a][b + 1] == i)
				//	dis[a][b + 1] = 0;
				if (map[a][b + 1] == 0)
					dis[a][b + 1] = dis[a][b] + 1;
				else
				{
					if (dis[a][b] < min)
						min = dis[a][b];
					break;
				}
			}
			if (!visit[a + 1][b] && map[a + 1][b] != i)
			{
				qqq.push({ a + 1,b });
				visit[a + 1][b] = 1;
				//if (map[a + 1][b] == i)
				//	dis[a + 1][b] = 0;
				if (map[a + 1][b] == 0)
					dis[a + 1][b] = dis[a][b] + 1;
				else
				{
					if (dis[a][b] < min)
						min = dis[a][b];
					break;
				}
			}
			if (!visit[a][b - 1] && map[a][b - 1] != i)
			{
				qqq.push({ a,b - 1 });
				visit[a][b - 1] = 1;
				//if (map[a][b - 1] == i)
				//	dis[a][b - 1] = 0;
				if (map[a][b - 1] == 0)
					dis[a][b - 1] = dis[a][b] + 1;
				else
				{
					if (dis[a][b] < min)
						min = dis[a][b];
					break;
				}
			}

		}

		/*for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
				cout << dis[i][j] << ' ';
			cout << '\n';
		}*/
		int max = 0;
		for (int j = 1; j < n + 1; j++)
		{
			for (int k = 1; k < n + 1; k++)
			{
				//if ((min > dis[j][k]) && (dis[j][k] != 0))
				//	min = dis[j][k]; // �ִܰŸ�
				if (max < dis[j][k])
					max = dis[j][k];
				dis[j][k] = 0; // dis �ʱ�ȭ
			}
		}
		if (min > max)
			min = max;
		//gq.pop(); // ���� ������ ������

		//cout << i << "@$!#!@#" << '\n';
	}

	cout << min;

	return 0;
}