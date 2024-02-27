#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int arr[10005];
	int dp[10005];
	memset(dp, 0, sizeof(dp));
	arr[0] = 0;

	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; i - j >= 0; j++)
		{
			if (arr[i] < arr[i - j])
			{
				if (dp[i] < dp[i - j] + 1)
					dp[i] = dp[i - j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 1; i < n + 1; i++)
		if (max < dp[i])
			max = dp[i];
	cout << max + 1 << '\n';

	return 0;

}