#include <iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	map<int, int> m;
	int N, M, n;

	cin >> N;
	while (N--)
	{
		cin >> n;
		m[n]++; // 맵에 저장
	}

	cin >> M;
	while (M--)
	{
		cin >> n;
		auto it = m.find(n); // 맵에사 n을 못 찾으면 it = m.end()가 된다.

		if (it != m.end())
			cout << it->second << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}