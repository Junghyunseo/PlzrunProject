#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	vector<int> v;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		v.push_back(s[i] - '0');
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}