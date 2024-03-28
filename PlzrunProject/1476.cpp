#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int E, S, M;
	int a = 0, b = 0, c = 0, ans;

	cin >> E >> S >> M;

	for (int i = 0; ;)
	{
		if (a >= 15)
			a = 1;
		else
			a++;
		if (b >= 28)
			b = 1;
		else
			b++;
		if (c >= 19)
			c = 1;
		else
			c++;
		i++;

		if (a == E && b == S && c == M)
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}