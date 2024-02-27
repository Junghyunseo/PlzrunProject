#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int a, p;

int ppp(int n)
{
	int ans = 0;
	for (int i = 10; n > 0; i *= 10)
	{
		ans += pow(n % 10, p);
		n /= 10;
	}
	return ans;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	vector<int> v;

	cin >> a >> p;

	v.push_back(a);

	for (int i = 1; ; i++)
	{
		int n = ppp(v[i - 1]);

		for (int j = 0; j < i; j++)
		{
			if (v[j] == n)
			{
				cout << j;
				return 0;
			}
		}
		v.push_back(n);
	}

	return 0;
}