#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dp[35];
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;

	for (int i = 5; i < n + 1; i++)
	{
		if (i % 2) // 3xn 벽에서 n이 홀수일 경우 2x1, 1x2 타일로 채울 수 있는 방법이 없음
			dp[i] = 0;
		else
		{
			//dp[i] = dp[i - 2] * 3 + dp[i - 4] * 2 + 2;
			dp[i] += dp[i - 2] * 3;
			for (int j = 2; i - 2 * j >= 0; j++)
				dp[i] += dp[i - 2 * j] * 2;
		}
	}
	cout << dp[n];
	return 0;
}