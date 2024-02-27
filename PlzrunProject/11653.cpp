#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;

	cin >> n;

	for (int i = 2; i < n + 1; i++)
	{
		while (!(n % i))
		{
			cout << i << '\n';
			n /= i;
		}
		if (n == 1)
			break;
	}
	return 0;
}