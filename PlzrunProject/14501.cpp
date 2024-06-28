#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[21]{};
	int ans[21]{};
	int price[21]{};

	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
		cin >> price[i];
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (price[i] > ans[i + arr[i] - 1])
			ans[i + arr[i] - 1] = price[i];
	}
	int sum = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cout << ans[i] << ' ';
		sum += ans[i];
	}
	cout << sum;
	return 0;
}