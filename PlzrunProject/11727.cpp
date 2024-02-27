#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[10005];

	cin >> n;

	arr[0] = 1;
	arr[1] = 3;

	for (int i = 2; i < n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;

	cout << arr[n - 1];
	return 0;
}