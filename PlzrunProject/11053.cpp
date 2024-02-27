#include <iostream>
#include <string.h>
using namespace std;

int main(void) // memset: 0 or 1�θ� �ʱ�ȭ ����
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[1001];
	int dp[1001];
	arr[0] = 0;
	memset(dp, 0, sizeof(arr)); // �������� ������ ���� ��½� 1 ���ؼ� ����ؾ� ��
	// memset�� fill���� �����ٰ� �Ѵ�.

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
				if (count == 0) // ó�� ���°ſ� ������ +1 �ϰ� ���Ŀ� ���� �͵�� �񱳸� ���� �� ū �� ����
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
	// dp �� �� �ִ��� ����Ѵ�.
	int max = 0;
	for (int i = 1; i < n + 1; i++)
		if (dp[i] > max)
			max = dp[i];

	cout << max + 1 << '\n';
	return 0;

}