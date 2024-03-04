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
		m[n]++; // �ʿ� ����
	}

	cin >> M;
	while (M--)
	{
		cin >> n;
		auto it = m.find(n); // �ʿ��� n�� �� ã���� it = m.end()�� �ȴ�.

		if (it != m.end())
			cout << it->second << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}