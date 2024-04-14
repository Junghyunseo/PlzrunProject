#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, k, l;

	cin >> n >> k >> l;

	if (k > l)
	{
		int tmp = l;
		l = k;
		k = tmp;
	}

	int cnt = 0;
	bool isMeet = false;

	while (1)
	{
		cnt++;
		if (k + 1 == l)
		{
			if (k % 2 && !(l % 2))
			{
				isMeet = true;
				break;
			}
		}
		if (k % 2)
		{
			k /= 2;
			k++;
		}
		else
			k /= 2;
		if (l % 2)
		{
			l /= 2;
			l++;
		}
		else
			l /= 2;
		if (!k)
			break;
	}

	if (isMeet)
		cout << cnt;
	else
		cout << -1;

	return 0;
}