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
		while (1) // n 이하의 수 중에서 가장 가까운 제곱수를 만드는 num 찾기
		{
			num++;
			if (i - sq[num] < 0)
			{
				num--;
				break;
			}
		}
		if (!(i - sq[num])) // n = num이 제곱수이면 무조건 답은 1
			dp[i] = 1;
		else
		{
			dp[i] = 1 + dp[i - sq[num]]; // 우선 가장 가까운 제곱수 + dp[남은 숫자]로 설정
			for (int j = 0; j < num; num--) // 그 제곱수보다 작은 제곱수의 dp값과의 조합도 다 비교하기
			{
				if (dp[i] > 1 + dp[i - sq[num]])
					dp[i] = 1 + dp[i - sq[num]];
			}
		}
	}

	cout << dp[n];
	return 0;
}