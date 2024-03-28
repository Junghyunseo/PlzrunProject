#include <iostream>
#include<queue>
#include<math.h>

using namespace std;

int a, b;
bool isNotPrime[10002]{}; // 소수이면 false
bool isVisit[10002]{}; // 해당 수의 방문 여부

bool isOnlyOne(int a, int b) // 숫자가 하나만 다른지 체크
{
	int x = 0;
	for (int i = 1000; i > 0; i /= 10)
	{
		if (a / i == b / i)
			x++;
		a %= i;
		b %= i;
	}
	if (x == 3)
		return true;
	else
		return false;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	queue<int> q;

	for (int i = 2; i * i <= 10000; i++) // 체
		if (!isNotPrime[i])
			for (int j = i * i; j <= 10000; j += i)
				isNotPrime[j] = true; // 소수가 아님을 표시

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		q.push(a);
		isVisit[a] = true;

		int cnt = 0;
		bool isFind = false;

		while (1)
		{
			fill(isVisit, isVisit + 10000, false);
			int size = q.size();

			for (int j = 0; j < size; j++)
			{
				int a = q.front();
				isVisit[a] = true;
				q.pop();
				if (a == b)
				{
					isFind = true;
					break;
				}

				for (int k = 1; k < 10000; k *= 10)
				{
					for (int u = 1; u < 10; u++)
					{
						if (a + k * u < 10000)
						{
							if (!isNotPrime[a + k * u] && !isVisit[a + k * u] && isOnlyOne(a, a + k * u))
							{
								q.push(a + k * u);
								isVisit[a + k * u] = true;
							}
						}
						if (a - k * u > 1000)
						{
							if (!isNotPrime[a - k * u] && !isVisit[a - k * u] && isOnlyOne(a, a - k * u))
							{
								q.push(a - k * u);
								isVisit[a - k * u] = true;
							}
						}
					}
				}
			}

			if (isFind)
				break;
			cnt++;
		}

		cout << cnt << '\n';
			while (!q.empty())
				q.pop();
	}

	return 0;
}