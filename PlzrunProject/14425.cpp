#include <iostream>
#include<map>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M, ans = 0;
	map<string, int> m;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		m.insert({ tmp,i });
	}
	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (m.find(tmp) != m.end())
			ans++;
	}
	cout << ans;
	return 0;
}