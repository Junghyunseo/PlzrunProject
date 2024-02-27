#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	int arr[12];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> n;

		for (int i = 3; i < n; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		cout << arr[n - 1] << '\n';
	}
	return 0;
}