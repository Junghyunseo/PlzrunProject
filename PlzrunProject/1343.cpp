#include <iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string s;
	queue<char> q;

	cin >> s;
	bool isPossible = true;
	int size = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'X')
			size++;
		else
		{
			if (!(size % 2)) // 2의 배수
			{
				if (size % 4 > 0) // 4의 배수가 아닌 2의 배수
				{
					for (int j = 0; j < size - 2; j++)
						q.push('A');
					q.push('B');
					q.push('B');
				}
				else // 4의 배수
				{
					for (int j = 0; j < size; j++)
						q.push('A');
				}
				q.push('.');
				size = 0;
			}
			else
			{
				isPossible = false;
			}
		}
	}
	if (!(size % 2))
	{
		if (size % 4 > 0) // 4의 배수가 아닌 2의 배수
		{
			for (int j = 0; j < size - 2; j++)
				q.push('A');
			q.push('B');
			q.push('B');
		}
		else // 4의 배수
		{
			for (int j = 0; j < size; j++)
				q.push('A');
		}
	}
	else
		isPossible = false;

	if (isPossible)
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}
	else
		cout << -1;
	return 0;
}