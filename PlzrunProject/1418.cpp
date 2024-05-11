#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio();

	int N, K, ans = 0;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
	{
		int tmp = i;
		for (int j = 2; j <= K; j++)
			while (!(tmp % j))
				tmp /= j;
		if (tmp == 1)
			ans++;
	}
	cout << ans;

	return 0;
}