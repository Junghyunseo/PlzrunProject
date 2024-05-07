#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	char arr[52][52];
	char cnt[52][52]{};
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			cin >> arr[i][j];
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			if (arr[i][j] == 'Y')
			{
				cnt[i][j] = 'Y';
				for (int k = 1; k < N + 1; k++)
					if (arr[j][k] == 'Y' && i != k)
						cnt[i][k] = 'Y';
			}
	int max = 0;
	for (int i = 1; i < N + 1; i++)
	{
		int ans = 0;
		for (int j = 0; j < N + 1; j++)
			if (cnt[i][j] == 'Y')
				ans++;
		if (max < ans)
			max = ans;
	}
	cout << max;
	return 0;
}