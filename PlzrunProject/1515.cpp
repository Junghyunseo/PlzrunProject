#include<iostream>
#include<queue>
#include<string>
#include<math.h>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	queue<int> q;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++)
		q.push(s[i] - '0');

	int N = 1;
	while (!q.empty())
	{
		int digit = 1; // N의 자릿수
		// N의 자릿수 구하기
		int i = 10;
		while (N / i > 0)
		{
			i *= 10;
			digit++;
		}

		i = pow(10, digit - 1);

		int tmpNum = N;
		for (int j = 0; j < digit; j++)
		{
			int xx = tmpNum / i;
			if (q.front() == xx)
				q.pop();
			tmpNum %= i;
			i /= 10;
			if (q.empty())
				break;
		}
		if(!q.empty())
			N++;
	}
	cout << N;
	return 0;
}