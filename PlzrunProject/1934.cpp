#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int t, M, a, b;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;

		if (a > b)
			M = b;
		else
			M = a;

		// 최대공약수 구하기
		for (int j = M; j > 0; j--)
		{
			if (!(a % j) && !(b % j))
			{
				M = j;
				break;
			}
		}

		cout << a * b / M << '\n';
	}

	return 0;
}