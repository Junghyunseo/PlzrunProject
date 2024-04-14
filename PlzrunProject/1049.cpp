#include <iostream>
#include<math.h>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int packageMin = 1e9;
	int eachMin = 1e9;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		if (packageMin > tmp1)
			packageMin = tmp1;
		if (eachMin > tmp2)
			eachMin = tmp2;
	}

	int ans = 1e9;

	for (int i = 0; N - 6 * i > 0; i++)
	{
		int tmp = packageMin * i + eachMin * (N - 6 * i);
		if (ans > tmp)
			ans = tmp;
	}

	int cnt = N / 6;
	if (N % 6 > 0)
		cnt += 1;
	if (cnt * packageMin < ans)
		ans = cnt * packageMin;
	cout << ans;
	
	return 0;
}