#include<iostream>

using namespace std;

int N, M, T;
long long dp[32]{};

long long comb(long long m, long long n)
{
	dp[1] = M;
	for (int i = 2; i < N + 1; i++)
	{
		M--;
		dp[i] = dp[i - 1] * M / i;
	}
	return dp[N];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		cout << comb(M, N) << '\n';
	}
	return 0;
}