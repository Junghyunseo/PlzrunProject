#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sum(string s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			sum += s[i] - '0';
	return sum;
}

bool comp(string s1, string s2)
{
	if (s1.size() == s2.size())
		if (sum(s1) == sum(s2))
			return s1 < s2;
		else
			return sum(s1) < sum(s2);
	else
		return s1.size() < s2.size();
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	vector<string> v;
	int N;
	string tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}