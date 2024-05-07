#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	long long N, S;
	cin >> N >> S;
	vector<long long> v;
	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int ans = 0;
	for (int i = 1; i < N + 1; i++) // 크기가 1인 부분 수열부터 N인 부분 수열
	{
		for (int j = 0; j + i < N + 1; j++) // 시작점이 0부터 될 때까지
		{
			long long sum = 0;
			for (int k = 0; k < i; k++) // 각 시작점에서 크기 N만큼의 부분수열
				sum += v[j + k];
			cout << sum << ' ';
			if (sum == S)
				ans++;
		}
	}
	cout << ans;
	return 0;
}