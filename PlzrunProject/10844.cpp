#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0, mod = 1000000000;
	int arr[100][10] = {
		0,
	};

	for (int i = 1; i < 10; i++)
		arr[0][i] = 1;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1] % mod;
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1] % mod;
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % mod;
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + arr[n - 1][i]) % mod;

	cout << ans;

	return 0;
}