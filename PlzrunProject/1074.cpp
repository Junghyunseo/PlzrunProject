#include<iostream>
#include<math.h>

using namespace std;

int N, r, c, ans = 0;

void rec(int x, int y, int n)
{
	if (n == 0)
	{
		cout << ans;
		return;
	}
	if (x < pow(2, n - 1) && y < pow(2, n - 1))
		rec(x, y, n - 1);
	else if (x < pow(2, n - 1) && y >= pow(2, n - 1))
	{
		ans += pow(2, 2 * n - 2);
		rec(x, y - pow(2, n - 1), n - 1);
	}
	else if (x >= pow(2, n - 1) && y < pow(2, n - 1))
	{
		ans += pow(2, 2 * n - 1);
		rec(x - pow(2, n - 1), y, n - 1);
	}
	else
	{
		ans += pow(2, 2 * n - 2) * 3;
		rec(x - pow(2, n - 1), y - pow(2, n - 1), n - 1);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> r >> c;

	rec(r, c, N);

	return 0;
}