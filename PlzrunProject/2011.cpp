#include <iostream>
#define mod 1000000

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	long long arr[5005];
	long long dp[2][5005]; // dp[0][i]에는 앞의 숫자들과 arr[0][i]를 따로 쓰는 경우의 수,
	// dp[1][i]에는 dp[i-1]과 dp[i]를 한 숫자로 같이 쓰는 경우의 수.

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		arr[i] = s[i] - '0';
	}

	dp[1][0] = 0;

	if (!arr[0]) // 0으로 시작하는 숫자는 무조건 안 됨
		dp[0][0] = 0;
	else
		dp[0][0] = 1;

	if (s.size() > 1)
	{
		if (arr[0] == 1)
		{
			if (!arr[1]) // 10이면 무조건 같이
			{
				dp[0][1] = 0;
				dp[1][1] = 1;
			}
			else
			{
				dp[0][1] = 1;
				dp[1][1] = 1;
			}
		}
		else if (arr[0] == 2 && arr[1] < 7)
		{
			if (!arr[1]) // 20이면 무조건 같이
			{
				dp[0][1] = 0;
				dp[1][1] = 1;
			}
			else
			{
				dp[0][1] = 1;
				dp[1][1] = 1;
			}
		}
		else if (arr[0] == 0)
		{
			dp[0][1] = 0;
			dp[1][1] = 0;
		}
		else if (arr[0] > 2 && arr[1] == 0)
		{
			dp[0][1] = 0;
			dp[1][1] = 0;
		}
		else
		{
			dp[0][1] = 1;
			dp[1][1] = 0;
		}
	}

	for (int i = 2; i < s.size(); i++)
	{
		if (!arr[i - 1])
		{
			dp[1][i] = 0;
			dp[0][i] = dp[1][i - 1];
			if (!arr[i])
			{
				dp[0][i] = 0;
				dp[1][i] = 0;
				dp[0][i - 1] = 0;
				dp[1][i - 1] = 0;
				dp[0][i - 2] = 0;
				dp[1][i - 2] = 0;
			}
		}
		else if (arr[i - 1] == 1) // 10몇 가능할 때
		{
			if (arr[i])
			{
				dp[0][i] = dp[0][i - 2] + dp[1][i - 2];
				dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
			}
			else // 10일 때
			{
				dp[0][i] = 0;
				dp[1][i] = dp[0][i - 2] + dp[1][i - 2];
			}
		}
		else if (arr[i - 1] == 2 && arr[i] < 7) // 20~26
		{
			if (arr[i]) // 21~26일 때
			{
				dp[0][i] = dp[0][i - 2] + dp[1][i - 2];
				dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
			}
			else // 20일 때
			{
				dp[0][i] = 0;
				dp[1][i] = dp[0][i - 2] + dp[1][i - 2];
			}
		}
		else if (arr[i - 1] > 2 && arr[i] == 0) // 30, 40, ..., 90의 경우
		{
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		else // i-1번째 수와 i번째 수를 합쳐서 쓸 수 없을 때
		{
			dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
			dp[1][i] = 0;
		}
		dp[0][i] %= mod;
		dp[1][i] %= mod;
	}

	cout << (dp[0][s.size() - 1] + dp[1][s.size() - 1]) % mod << '\n';
	/*for (int i = 0; i < s.size(); i++)
	{
		cout << dp[0][i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < s.size(); i++)
	{
		cout << dp[1][i] << ' ';
	}*/
	return 0;
}