#include<iostream>
#include<algorithm>

using namespace std;

long long n, m, height = 0;
long long arr[1000002];
long long st = 0, mid, en, toTake = 0;

long long binary(long long num)
{
	en = num;
	while (st <= en)
	{
		mid = (st + en) / 2;
		toTake = 0; // 가져갈 나무 길이 합

		for (int i = 0; i < n; i++)
			if (arr[i] - mid > 0) // 가져갈 나무들 더하기
				toTake += arr[i] - mid;
		if (toTake >= m)
		{
			if (height < mid)
				height = mid;
			st = mid + 1;
		}
		else
			en = mid - 1;
	}
	return height;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cout << binary(arr[n - 1]);
	return 0;
}