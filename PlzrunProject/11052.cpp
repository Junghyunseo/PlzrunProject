#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[1005];
	int dp[1005];

	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; i - j > 0; j++)
		{
			if (dp[i] < dp[j] + dp[i - j])
				dp[i] = dp[j] + dp[i - j];
		}
	}

	cout << dp[n];
	return 0;
}