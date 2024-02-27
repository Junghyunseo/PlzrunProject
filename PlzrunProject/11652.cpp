#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, j = 0;
	long long arr[100000];
	long long arr2[2][100000];

	memset(arr2, 0, sizeof(arr2));

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	arr2[0][0] = arr[0];
	arr2[1][0] = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
			arr2[1][j]++;
		else
		{
			j++;
			arr2[0][j] = arr[i];
			arr2[1][j] = 1;
		}
	}
	long long max = arr2[1][j];
	int maxIndex = j;

	for (int i = j; i >= 0; i--)
	{
		if (max <= arr2[1][i])
		{
			max = arr2[1][i];
			maxIndex = i;
		}
	}
	cout << arr2[0][maxIndex] << '\n';
	return 0;
}