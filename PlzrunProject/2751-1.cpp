#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	int arr[2][2000001];

	for (int i = 0; i < 2000001; i++)
		arr[1][i] = 0;

	for (int i = 0; i < 1000000; i++)
		arr[0][i] = -1000000 + i;

	for (int i = 1000000; i < 2000001; i++)
		arr[0][i] = i - 1000000;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		arr[1][t + 1000000] = 1;
	}

	for (int i = 0; i < 2000001; i++)
		if (arr[1][i])
			cout << arr[0][i] << '\n';

	return 0;
}