#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M, n;
	vector<int>v;

	cin >> N;
	while (N--)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	cin >> M;
	while (M--)
	{
		cin >> n;
		cout << upper_bound(v.begin(), v.end(), n) - lower_bound(v.begin(), v.end(), n) << ' ';
	}

	return 0;
}