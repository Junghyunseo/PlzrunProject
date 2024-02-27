#include <iostream>
#include <string.h>
using namespace std;

int main(void) // memset: 0 or 1로만 초기화 가능
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[1001];
	int dp[1001];
	arr[0] = 0;
	memset(dp, 0, sizeof(arr)); // 마지막에 답으로 길이 출력시 1 더해서 출력해야 함
	// memset이 fill보다 빠르다고 한다.

	cin >> n;
	int count = 0;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];

	for (int i = 2; i < n + 1; i++)
	{
		count = 0;
		for (int j = 0; i - j - 1 > 0; j++)
		{
			if (arr[i - j - 1] < arr[i])
			{
				if (count == 0) // 처음 나온거에 무조건 +1 하고 이후엔 앞의 것들과 비교를 통해 더 큰 값 저장
				{
					dp[i] = dp[i - j - 1] + 1;
					count = 1;
				}
				else
				{
					if (dp[i - j - 1] + 1 > dp[i])
						dp[i] = dp[i - j - 1] + 1;
				}
			}
		}
	}
	// dp 값 중 최댓값을 출력한다.
	int max = 0;
	for (int i = 1; i < n + 1; i++)
		if (dp[i] > max)
			max = dp[i];

	cout << max + 1 << '\n';
	return 0;

}