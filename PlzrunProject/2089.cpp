#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	int a = 2;

	stack<int> s;

	cin >> n;

	while (1)
	{
		if (n == 1)
		{
			s.push(n);
			break;
		}
		else
		{
			if (n < 0)
			{
				n *= -1;
				s.push(n % a);
				if (n == 1)
				{
					s.push(n);
					break;
				}
				n /= a;
			}
			else
			{
				s.push(n % a);
				n = -1 * (n - n % a) / 2;
			}
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}