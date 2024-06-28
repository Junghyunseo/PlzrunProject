#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int ans = 0;
	int digit = 0;
	cin >> N;
	int i = 1;

	while(1)
	{
		if (N / i > 0)
		{
			digit++;
			i *= 10;
		}
		else
			break;
	}

	for (int i = 1; i < digit; i++)
		ans += i * 9 * pow(10, i - 1);
	ans += digit * (N - pow(10, digit - 1) + 1);
	cout << ans;


	return 0;
}