#include<iostream>

using namespace std;

int N, K, arr[11];

int func(int k)
{
	int ans = 0;
	for (int i = N; i > 0; i--)
	{
		if (k / arr[i] > 0)
		{
			ans += k / arr[i];
			k %= arr[i];
		}
	}
	return ans;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> K;

	for (int i = 1; i < N + 1; i++)
		cin >> arr[i];

	cout << func(K);

	return 0;
}