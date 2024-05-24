#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M, ans = 0;
	map<string, int> m;
	vector<string> vs;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		string tmp;
		cin >> tmp;
		if (m.find(tmp) == m.end())
			m[tmp] = 1;
		else
		{
			ans++;
			vs.push_back(tmp);
		}
	}
	sort(vs.begin(), vs.end());
	cout << ans << '\n';
	for (int i = 0; i < vs.size(); i++)
		cout << vs[i] << '\n';
	return 0;
}