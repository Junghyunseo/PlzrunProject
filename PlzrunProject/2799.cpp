#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int M, N;
	cin >> M >> N;

	char arr[501][501]{};
	int ans[5]{};

	for (int i = 0; i < 5 * M + 1; i++)
		for (int j = 0; j < 5 * N + 1; j++)
			cin >> arr[i][j];

	int x = 4;
	for (int i = 0; i < M; i++)
	{
		int y = 1;

		for (int j = 0; j < N; j++)
		{
			int isGood = false;
			for (int k = 0; k < 4; k++)
			{
				if (arr[x - k][y] == '*')
				{
					ans[(x - k) % 5]++;
					isGood = true;
					break;
				}
			}
			if (!isGood)
				ans[0]++;
			y += 5;
		}

		x += 5;
	}

	for (int i = 0; i < 5; i++)
		cout << ans[i] << ' ';
	return 0;
}