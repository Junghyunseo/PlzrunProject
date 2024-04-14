#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, arr[15]{};
	cin >> N;

	arr[0] = 3;
	for (int i = 1; i < 15; i++)
	{
		arr[i] = 2 * arr[i - 1] - 1;
	}
	cout << arr[N - 1] * arr[N - 1];
	return 0;
}