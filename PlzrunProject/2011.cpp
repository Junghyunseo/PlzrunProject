#include <iostream>
#define mod 1000000

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	long long arr[5005];
	long long dp[2][5005]; // dp[0][i]���� ���� ���ڵ�� arr[0][i]�� ���� ���� ����� ��,
	// dp[1][i]���� dp[i-1]�� dp[i]�� �� ���ڷ� ���� ���� ����� ��.

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		arr[i] = s[i] - '0';
	}

	dp[1][0] = 0;

	if (!arr[0]) // 0���� �����ϴ� ���ڴ� ������ �� ��
		dp[0][0] = 0;
	else
		dp[0][0] = 1;

	if (s.size() > 1)
	{
		if (arr[0] == 1)
		{
			if (!arr[1]) // 10�̸� ������ ����
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
			if (!arr[1]) // 20�̸� ������ ����
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
		else if (arr[i - 1] == 1) // 10�� ������ ��
		{
			if (arr[i])
			{
				dp[0][i] = dp[0][i - 2] + dp[1][i - 2];
				dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
			}
			else // 10�� ��
			{
				dp[0][i] = 0;
				dp[1][i] = dp[0][i - 2] + dp[1][i - 2];
			}
		}
		else if (arr[i - 1] == 2 && arr[i] < 7) // 20~26
		{
			if (arr[i]) // 21~26�� ��
			{
				dp[0][i] = dp[0][i - 2] + dp[1][i - 2];
				dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
			}
			else // 20�� ��
			{
				dp[0][i] = 0;
				dp[1][i] = dp[0][i - 2] + dp[1][i - 2];
			}
		}
		else if (arr[i - 1] > 2 && arr[i] == 0) // 30, 40, ..., 90�� ���
		{
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		else // i-1��° ���� i��° ���� ���ļ� �� �� ���� ��
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