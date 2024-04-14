#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<int> v;
	vector<int> v2;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0; i < v.size(); i++)
		cout << lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() << ' ';
	return 0;
}