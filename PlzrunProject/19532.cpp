#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int a, b, c, d, e, f;
	int x = -999, y = -999;
	int ansX = 0, ansY = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for(int i=0;i<=1998;i++)
	{
		for (int j = 0; j <= 1998; j++)
		{
			if (a * (x + i) + b * (y + j) == c)
			{
				if (d * (x + i) + e * (y + j) == f)
				{
					ansX = x + i;
					ansY = y + j;
					break;
				}
			}
		}
	}
	cout << ansX << ' ' << ansY;

	return 0;
}