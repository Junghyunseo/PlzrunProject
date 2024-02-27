#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y;
	vector<pair<int, int>> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].second << ' ' << v[i].first << '\n';
	return 0;
}