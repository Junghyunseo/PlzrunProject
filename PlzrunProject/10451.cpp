#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int visit[1001]{};

void dfs(int n)
{
	if (!visit[n])
	{
		visit[n] = 1;
		dfs(v[n]);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int t, n, ans = 0;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		v.push_back(0); // 인덱스 0 사용 안 함
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		for (int i = 1; i < v.size(); i++)
		{
			if (!visit[i])
			{
				visit[i] = 1;
				dfs(v[i]);
				ans++;
			}
		}
		cout << ans << '\n';
		ans = 0;
		fill(visit, visit + 1001, 0);
		while (!v.empty())
			v.pop_back();
	}

	return 0;
}