#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long dp[91][2] = {
		0,
	};
	int n;
	long long ans = 0;

	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	ans = dp[n][0] + dp[n][1];
	cout << ans;
	return 0;
}