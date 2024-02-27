#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(tuple<int, int, int, string> a, tuple<int, int, int, string> b)
{
	if (get<2>(a) == get<2>(b) && get<1>(a) == get<1>(b) && get<0>(a) == get<0>(b)) // 주의!
		return get<3>(a) < get<3>(b);
	if (get<1>(a) == get<1>(b) && get<0>(a) == get<0>(b))
		return get<2>(a) > get<2>(b);
	if (get<0>(a) == get<0>(b))
		return get<1>(a) < get<1>(b);
	return get<0>(a) > get<0>(b);

}

int main(void)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	int n, x, y, z;
	string s;
	vector<tuple<int, int, int, string>> v; // 국 영 수 이름

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> x >> y >> z;
		v.push_back({ x,y,z,s });
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++)
		cout << get<3>(v[i]) << '\n';
	return 0;
}