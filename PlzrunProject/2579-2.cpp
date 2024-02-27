#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[305];
	int dp[305];
	arr[0] = 0;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i < n + 1; i++)
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);

	cout << dp[n] << '\n';
	return 0;
}