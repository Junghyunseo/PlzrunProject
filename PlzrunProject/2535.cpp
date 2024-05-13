#include <iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(tuple<int, int, int> &v1, tuple<int, int, int> &v2)
{
	return get<2>(v1) > get<2>(v2);//tuple 3번째 값으로 비교
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<tuple<int, int, int>> t;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		t.push_back({ a,b,c });
	}
	sort(t.begin(), t.end(), comp);

	int a = get<0>(t[0]);
	int b = get<0>(t[1]);
	cout << a << ' ' << get<1>(t[0]) << '\n';
	cout << b << ' ' << get<1>(t[1]) << '\n';
	for (int i = 2; ; i++)
	{
		int c = get<0>(t[i]);
		if ((a == b) && (b == c))
			continue;
		else
		{
			cout << get<0>(t[i]) << ' ' << get<1>(t[i]) << '\n';
			break;
		}
	}
	return 0;
}