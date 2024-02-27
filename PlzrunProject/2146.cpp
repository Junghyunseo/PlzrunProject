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
	queue<pair<int, int>> gq; // 각 육지의 시작 인덱스

	cin >> n;

	for (int i = 0; i < 102; i++) // 테두리는 방문 표시
		for (int j = 0; j < 102; j++)
			if (i == 0 || j == 0 || i > n || j > n)
				visit[i][j] = 1;

	for (int i = 1; i < n + 1; i++) // 육지 입력받기
		for (int j = 1; j < n + 1; j++)
			cin >> map[i][j];

	int g = 1; // 육지 번호

	// 육지 번호 부여
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (!visit[i][j] && map[i][j]) // 방문을 안 했고, 지도에 1표시 있으면
			{
				q.push({ i,j }); // 각 육지의 시작점
				gq.push({ i,j }); // 육지의 시작인덱스 넣기
				visit[i][j] = 1; // 방문 표시

				while (!q.empty())
				{
					int a = q.front().first;
					int b = q.front().second;
					visit[a][b] = 1; // 방문 표시
					map[a][b] = g; // 육지 번호 부여
					q.pop(); // 방문했으면 빼기

					// 상하좌우칸 중 조건 만족하면 스택에 넣기
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
				g++; // 육지 번호 증가
			}
		}
	}


	//while(!gq.empty())

	int min = 1e9; // 최단거리

	for (int i = 1; i < g; i++) // 각 육지마다 다른 육지까지의 최단거리를 구하기 i: 육지 번호
	{
		// visit 초기화
		for (int j = 1; j < n + 1; j++)
			for (int k = 1; k < n + 1; k++)
				visit[j][k] = 0;

		int a = gq.front().first; // 처음엔 육지의 시작점 인덱스
		int b = gq.front().second;
		gq.pop();


		queue<pair<int, int>> qqq;
		// 해안가에 있는 육지 덱스를 queue에 넣기
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
			visit[a][b] = 1; // 방문 표시


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
				//	min = dis[j][k]; // 최단거리
				if (max < dis[j][k])
					max = dis[j][k];
				dis[j][k] = 0; // dis 초기화
			}
		}
		if (min > max)
			min = max;
		//gq.pop(); // 육지 시작점 꺼내기

		//cout << i << "@$!#!@#" << '\n';
	}

	cout << min;

	return 0;
}