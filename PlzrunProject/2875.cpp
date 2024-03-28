#include<iostream>

using namespace std;

int N, M, K;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	int ans = 0;

	if (N / 2 >= M)
	{
		ans = M; // 일단 만들어지는 팀의 개수 
		N -= M * 2;
		M = 0;
	}
	else
	{
		ans = N / 2; // 일단 만들어지는 팀의 개수
		M -= N / 2;
		N = 0;
	}

	while ((M || N) && K)
	{
		if (M > 0)
		{
			M -= 1;
			K--;
		}
		else
		{
			N -= 1;
			K--;
		}
	}
	
	int minus = 0;

	if (K > 0)
	{
		while (1)
		{
			K -= 3;
			minus++;
			if (K <= 0)
				break;
		}
	}
	cout << ans - minus;

	return 0;
}