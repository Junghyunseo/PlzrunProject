#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	bool isFinish = false;
	int ans, ansL;
	int N, L;
	cin >> N >> L;

	for (int i = L; i <= 100; i++)
	{
		for (int j = 0; ; j++)
		{
			int sum = i * j + ((i * i) - i) / 2;
			//cout << i << ' ' << j << ' ' << sum << "!@3" << '\n';
			if (sum == N)
			{
				isFinish = true;
				ansL = i;
				ans = j;
				break;
			}
			if (sum > N)
				break;
		}
		if (isFinish)
			break;
	}

	if (isFinish)
		for (int i = 0; i < ansL; i++)
			cout << ans++ << ' ';
	else
		cout << -1;

	return 0;
}