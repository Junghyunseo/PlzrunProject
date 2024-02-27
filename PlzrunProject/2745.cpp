#include <iostream>
#include<string.h>
#include <math.h>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long b;
	long long ans = 0;
	string n;

	cin >> n >> b;

	if (b == 10)
	{
		for (int i = 0; i < n.length(); i++)
			cout << n[i];
	}

	else
	{
		for (int i = 0; i < n.length(); i++)
		{
			if (n[i] >= '0' && n[i] <= '9')
				ans += pow(b, n.size() - i - 1) * (n[i] - 48);
			else
				ans += pow(b, n.size() - i - 1) * (n[i] - 55);
		}
		cout << ans;
	}

	return 0;
}