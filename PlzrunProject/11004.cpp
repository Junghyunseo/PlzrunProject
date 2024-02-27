#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	long long arr[5000000];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cout << arr[k - 1];
	return 0;
}