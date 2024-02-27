#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[10005];
	int dp[10005];
	memset(dp, 0, sizeof(dp)); // dp의 모든 값들을 0으로 초기화
	arr[0] = 0;
	dp[0] = 0;

	cin >> n;

	for (int i = 1; i < n + 1; i++) // 수열 입력 받기
		cin >> arr[i];

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; i - j >= 0; j++) // arr[0]까지 비교가 들어간면 해당 arr=[i]보다 작은 수가 앞에 없었던 것임
		{
			if (arr[i - j] < arr[i])
			{
				if (dp[i] < dp[i - j] + arr[i])
					dp[i] = dp[i - j] + arr[i];
			}
		}
	}

	int max = 0;
	for (int i = 1; i < n + 1; i++)
		if (max < dp[i])
			max = dp[i];
	cout << max << '\n';
	return 0;

}