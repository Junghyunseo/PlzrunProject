#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int dp[2][10005];
	int arr[10005];
	memset(dp, 0, sizeof(dp));
	arr[0] = 0;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
	for (int i = 1; i < n + 1; i++) // 왼쪽에서부터 해당 수까지 증가한 수열의 최대 길이
	{
		for (int j = 1; i - j >= 0; j++)
		{
			if (arr[i] > arr[i - j])
			{
				if (dp[0][i] < dp[0][i - j] + 1)
					dp[0][i] = dp[0][i - j] + 1;
			}
		}
	}
	arr[n + 1] = 0;
	for (int i = n; i > 0; i--) // 해당 수부터 끝까지 감소한 수열의 최대 길이
	{
		for (int j = 1; i + j <= n + 1; j++)
		{
			if (arr[i] > arr[i + j])
			{
				if (dp[1][i] < dp[1][i + j] + 1)
					dp[1][i] = dp[1][i + j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n + 1; i++)
		if (max < dp[0][i] + dp[1][i])
			max = dp[0][i] + dp[1][i];

	cout << max - 1 << '\n'; // 해당수 양쪽 증가 감소한 수열의 길이를 더해서 해당 수가 겹치므로 1을 빼줘야 함
	/* 카운트 확인하기
	for (int i = 1; i < n + 1; i++)
		cout << dp[0][i] << ' ';
	cout << '\n';
	for (int i = 1; i < n + 1; i++)
		cout << dp[1][i] << ' ';*/
	return 0;
}