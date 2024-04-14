#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int X;
	cin >> X;

	int cnt = 0;
	while (X > 1)
	{
		if (X % 2 == 1)
			cnt++;
		X /= 2;
	}
	cnt++;
	cout << cnt;
	return 0;
}