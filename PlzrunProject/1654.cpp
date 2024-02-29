#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long k, n;
	long long arr[10005];
	cin >> k >> n;
	long long num = 0;

	for (long long i = 0; i < k; i++)
		cin >> arr[i];

	sort(arr, arr + k);

	long long small = 1, middle, big = arr[k - 1];
	long long max = 0;

	while (1)
	{
		long long count = 0;
		middle = (small + big) / 2;
		//cout << small << ' ' << middle << ' ' << big << "!@#$" << '\n';

		num = 0; // 만들어지는 랜선의 개수 초기화

		for (long long i = 0; i < k; i++)
			num += arr[i] / middle; // middle짜리 랜선의 개수 구하기

		if (num >= n) // n개 이상 만들어질 때
		{
			if (max < middle) // n개 이상 만들어지고, 그 길이가 최대이면
				max = middle;
			//cout << "max: " << max << '\n';

			small = middle; // 더 큰 쪽으로 업데이트
			middle = (small + big) / 2;
			//cout << "middle: " << middle << '\n';
		}
		else // n개 이상 만들어지지 않을 때
		{
			big = middle; // 더 작은 쪽으로 업데이트
			middle = (small + big) / 2;
		}
		num = 0; 
		for (long long i = 0; i < k; i++)
			num += arr[i] / big; // big짜리 랜선의 개수 구하기
		if (num >= n)
			if (max < big)
				max = big;
		num = 0;
		for (long long i = 0; i < k; i++)
			num += arr[i] / small; // small짜리 랜선의 개수 구하기
		if (num >= n)
			if (max < small)
				max = small;

		if (small == middle || middle == big)
		{
			//if (count)
				break;
			count++;
		}
	}
	cout << max;

	return 0;
}