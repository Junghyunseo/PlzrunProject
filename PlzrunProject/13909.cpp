#include<iostream>

using namespace std;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int cnt = 0;

	for (int i = 0; ; i++)
	{
		if (i * i < N && (i + 1) * (i + 1) >= N)
		{
			cnt = i;
			if ((i + 1) * (i + 1) == N)
				cnt += 1;
			break;
		}
	}
	cout << cnt;

	return 0;
}