#include <iostream>
#include <algorithm>

using namespace std;

int map[52][52]{};
int visit[52][52]{};
int ans = 0;

void dfs(int i, int j)
{
	for (int k = i - 1; k < i + 2; k++)
	{
		for (int l = j - 1; l < j + 2; l++)
		{
			if (map[k][l] && !visit[k][l])
			{
				visit[k][l] = 1;
				dfs(k, l);
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int w, h;

	while (1)
	{
		cin >> w >> h;

		if (!w && !h)
			break;

		for (int i = 0; i < 52; i++) // 벽 채우기
			for (int j = 0; j < 52; j++)
				if (j == 0 && j > w)
					if (i == 0 && i > h)
						visit[i][j] = 1;

		for (int i = 1; i < h + 1; i++)
			for (int j = 1; j < w + 1; j++)
				cin >> map[i][j];

		for (int i = 1; i < h + 1; i++)
		{
			for (int j = 1; j < w + 1; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					ans++;
					visit[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
		// clear
		ans = 0;
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
			{
				map[i][j] = 0;
				visit[i][j] = 0;
			}
	}
	return 0;
}