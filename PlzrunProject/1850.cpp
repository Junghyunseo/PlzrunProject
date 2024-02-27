#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long a, b, M;

	cin >> a >> b;

	if (a > b)
	{
		while (1)
		{
			M = a % b;
			if (!M)
				break;
			a = b;
			b = M;
		}
		M = b;
	}
	else
	{
		while (1)
		{
			M = b % a;
			if (!M)
				break;
			b = a;
			a = M;
		}
		M = a;
	}

	for (int i = 0; i < M; i++)
		cout << 1;

	return 0;
}