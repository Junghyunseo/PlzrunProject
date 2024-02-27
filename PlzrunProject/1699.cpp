#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int dp[100005];
	int sq[320];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 0; i < 320; i++)
		sq[i] = i * i;

	cin >> n;

	for (int i = 4; i < n + 1; i++)
	{
		int num = 0;
		while (1) // n ������ �� �߿��� ���� ����� �������� ����� num ã��
		{
			num++;
			if (i - sq[num] < 0)
			{
				num--;
				break;
			}
		}
		if (!(i - sq[num])) // n = num�� �������̸� ������ ���� 1
			dp[i] = 1;
		else
		{
			dp[i] = 1 + dp[i - sq[num]]; // �켱 ���� ����� ������ + dp[���� ����]�� ����
			for (int j = 0; j < num; num--) // �� ���������� ���� �������� dp������ ���յ� �� ���ϱ�
			{
				if (dp[i] > 1 + dp[i - sq[num]])
					dp[i] = 1 + dp[i - sq[num]];
			}
		}
	}

	cout << dp[n];
	return 0;
}