#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> v;
vector<int> v2;
int N;

bool isPre(int i, int j)
{
	bool b = true;
	for (int k = 0; k < v[i].size(); k++)
	{
		if (v[i][k] != v[j][k])
		{
			b = false;
			break;
		}
	}
	return b;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;
			else
				if (isPre(i, j))
					cnt++;
		}
		v2.push_back(cnt);
	}
	int ans = 0;
	for (int i = 0; i < v2.size(); i++)
		if (!v2[i])
			ans++;
	cout << ans;
	return 0;
}