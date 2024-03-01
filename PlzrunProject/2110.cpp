#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int n, c;
vector<int> house;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		house.push_back(num);
	}
	sort(house.begin(), house.end());

	int st = 1; // 최소 거리
	int en = house[n-1] - house[0]; // 가장 먼 두 집 사이 거리
	int mid;
	int ans = 0;

	while (st <= en)
	{
		mid = (st + en) / 2;
		int count = 1;
		int prehouse = house[0];

		for (int i = 1; i < n; i++)
		{
			if (house[i] - prehouse >= mid)
			{
				count++;
				prehouse = house[i];
			}
		}

		if (count >= c)
		{
			if (ans < mid)
				ans = mid;
			st = mid + 1;
		}
		else
			en = mid - 1;
	}

	cout << ans;

	return 0;
}