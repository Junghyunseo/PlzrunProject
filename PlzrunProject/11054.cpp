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
	for (int i = 1; i < n + 1; i++) // ���ʿ������� �ش� ������ ������ ������ �ִ� ����
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
	for (int i = n; i > 0; i--) // �ش� ������ ������ ������ ������ �ִ� ����
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

	cout << max - 1 << '\n'; // �ش�� ���� ���� ������ ������ ���̸� ���ؼ� �ش� ���� ��ġ�Ƿ� 1�� ����� ��
	/* ī��Ʈ Ȯ���ϱ�
	for (int i = 1; i < n + 1; i++)
		cout << dp[0][i] << ' ';
	cout << '\n';
	for (int i = 1; i < n + 1; i++)
		cout << dp[1][i] << ' ';*/
	return 0;
}