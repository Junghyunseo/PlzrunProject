#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int arr[100005];
	int dp[100005];
	memset(dp, 0, sizeof(dp));
	cin >> n;
	arr[0] = 0;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
	for (int i = 0; i < n + 1; i++)
		dp[i] = arr[i];

	for (int i = 1; i < n + 1; i++)
		if (dp[i] < dp[i - 1] + arr[i])
			dp[i] = dp[i - 1] + arr[i];

	int max = -100000005;
	for (int i = 1; i < n + 1; i++)
		if (max < dp[i])
			max = dp[i];
	cout << max << '\n';

	/*for (int i = 0; i < n + 1; i++)
		cout << dp[i] << ' ';
	cout << '\n';*/
	return 0;
}