#include <iostream>
#define mod 10007

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	int dp[1000][10] = {
		0,
	};

	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n - 1][i]) % mod;
	cout << ans;
	return 0;
}