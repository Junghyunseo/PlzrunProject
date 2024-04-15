#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	map<string, string, greater<string>> m;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		string log;
		cin >> s >> log;
		m[s] = log;
	}
	for (auto it=m.begin();it!=m.end();it++)
		if (it->second == "enter")
			cout << it->first << '\n';

	return 0;
}