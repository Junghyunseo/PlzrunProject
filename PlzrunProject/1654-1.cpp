#include <iostream>
#include <algorithm>

using namespace std;

long long arr[10002];
long long k, n;

long long binary(long long num)
{
	long long lan = 0;
	long long small = 1;
	long long mid, big = num;
	long long max = 0;

	while (small <= big)
	{
		lan = 0;
		mid = (small + big) / 2;

		for (int i = 0; i < k; i++)
			lan += arr[i] / mid; // 길이 mid짜리 랜선 개수

		if (lan >= n)
		{
			if(max < mid)
				max = mid;
			small = mid + 1;
		}
		else
			big = mid - 1;
	}

	return max;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	sort(arr, arr + k);

	cout << binary(arr[k - 1]);

	return 0;
}