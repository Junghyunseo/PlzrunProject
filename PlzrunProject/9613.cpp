#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	long long gcd;

	if (a > b)
	{
		gcd = b;
		while (1)
		{
			if (!(a % b))
				break;
			else
			{
				gcd = a % b;
				a = b;
				b = gcd;
			}
		}
		return gcd;
	}
	else
	{
		gcd = a;
		while (1)
		{
			if (!(b % a))
				break;
			else
			{
				gcd = b % a;
				b = a;
				a = gcd;
			}
		}
		return gcd;
	}
}

int main(void)
{
	int t, n;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long ans = 0;
		long long arr[105];
		cin >> n;

		for (int j = 0; j < n; j++)
			cin >> arr[j];

		for (int j = 0; j < n; j++)
		{
			for (int k = 1; j + k < n; k++)
			{
				ans += gcd(arr[j], arr[j + k]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}