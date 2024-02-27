#include <iostream>
#include <string.h>
#define mod 1000000000

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	long long dp[205][205];
	memset(dp, 0, sizeof(dp));

	cin >> n;
	cin >> k;

	for (int i = 1; i < n + 1; i++)
	{
		dp[1][i] = 1; // 1개로 n을 만드는 방법의 수는 1
		dp[2][i] = i + 1; // 2개로 n을 만드는 방법의 수는 n + 1
	}
	for (int i = 1; i < k + 1; i++)
		dp[i][0] = 1; // 0을 만드는 방법의 수는 1 : 몇 개든 0만 더할 수 있음

	for (int i = 3; i < k + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			dp[i][j] = dp[i][j - 1] % mod + dp[i - 1][j] % mod;
		}
	}
	cout << dp[k][n] % mod;

	/*for (int i = 1; i<k + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}*/
	return 0;
}