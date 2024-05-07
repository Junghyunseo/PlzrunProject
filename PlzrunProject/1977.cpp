#include<iostream>
#include<math.h>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = 0;
	bool isFirst = false;

	for (int i = 1; ; i++)
	{
		if (i * i > N)
			break;
		if (i * i >= M)
		{
			sum += i * i;
			if (!isFirst)
				min = i * i;
			isFirst = true;
		}
	}
	if (isFirst)
		cout << sum << '\n' << min;
	else
		cout << -1;
	return 0;
}