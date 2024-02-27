#include <iostream>

using namespace std;

int Max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int w[10001];
	int dp[10001];
	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> w[i];

	dp[0] = 0;
	dp[1] = w[1];
	dp[2] = dp[1] + w[2];

	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = Max(dp[i - 3] + w[i - 1] + w[i], dp[i - 2] + w[i], dp[i - 1]);
	}
	cout << dp[n] << '\n';
	return 0;
}