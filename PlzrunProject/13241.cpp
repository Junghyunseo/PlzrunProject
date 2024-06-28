#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long A, B;
	long long gcd = 1;
	cin >> A >> B;

	if (A < B)
	{
		int tmp = A;
		A = B;
		B = tmp;
	}
	int res = 0;
	int tmpA = A;
	int tmpB = B;
	while (1)
	{
		res = tmpA % tmpB;
		if (!res)
		{
			gcd = tmpB;
			break;
		}
		tmpA = tmpB;
		tmpB = res;
	}
	cout << A * B / gcd;
	return 0;
}