#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; // �׽�Ʈ ���̽��� ����
	int n;
	int st[2][100001] = { // ��ƼĿ
		0,
	};
	int dp[2][100001] = { // dp[i][j]: i, j������ ��ƼĿ�� ���� �ִ�. row 0�� row 1 �߿��� �ִ��� ���� ��.
		0,				  // ���� ��� dp[0][4]�� st[0][4]������ ��ƼĿ�� ���� �ִ���.
	};

	cin >> t;

	for (int i = 0; i < t; i++) // �׽�Ʈ ���̽� ����ŭ �ݺ�
	{
		cin >> n;
		for (int j = 0; j < 2; j++) // ��ƼĿ �Է� �ޱ�
		{
			for (int k = 0; k < n; k++)
				cin >> st[j][k];
		}

		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = dp[1][0] + st[0][1];
		dp[1][1] = dp[0][0] + st[1][1];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + st[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + st[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
	return 0;
}