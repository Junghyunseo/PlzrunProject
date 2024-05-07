#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int min = 5;

	for (int i = 0; i < v.size(); i++)
	{
		int tmpStart = v[i];
		int cnt = 0;
		for (int j = 1; j < 5; j++)
		{
			for (int k = i + 1; k < v.size(); k++)
				if (tmpStart + j == v[k])
				{
					cnt++;
					break;
				}
		}
		if (4 - cnt < min)
			min = 4 - cnt;
	}

	cout << min;

	return 0;
}