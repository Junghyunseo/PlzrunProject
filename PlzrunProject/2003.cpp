#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int arr[10001]{};

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1 ; ; j++)
		{
			if (arr[i] == M) // 혼자 M이 되는 경우
			{
				ans++;
				break;
			}
			if (arr[i] + arr[j] == M)
			{
				ans++;
				break;
			}
			else if (arr[i] + arr[j] > M)
				break;
			else
				arr[i] += arr[j];
		}
	}
	cout << ans;

	return 0;
}