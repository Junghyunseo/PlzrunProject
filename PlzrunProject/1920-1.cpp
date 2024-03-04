#include <iostream>
#include<algorithm>

using namespace std;
long long n, m;
long long arr[100001]{};

void search(int num)
{
	int st = 0;
	int mid;
	int en = n - 1;
	int count = 0;

	while (st <= en)
	{
		mid = (st + en) / 2;
		if (arr[mid] <= num)
		{
			if (arr[mid] == num)
				count = 1;
			st = mid + 1;
		}
		else
			en = mid - 1;
	}
	cout << count << '\n';
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		search(tmp);
	}

	return 0;
}