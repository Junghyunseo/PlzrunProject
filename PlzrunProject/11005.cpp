#include <iostream>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long n;
	int b;
	char arr[50];
	stack<int> s;

	cin >> n >> b;

	for (int i = 0; i < 26; i++)
		arr[i] = 'A' + i;

	;	if (b == 10)
		cout << n;
	else
	{
		while (1)
		{
			s.push(n % b);
			n /= b;
			if (!n)
				break;
		}
		while (!s.empty())
		{
			if (b < 10)
			{
				cout << s.top();
				s.pop();
			}
			else
			{
				if (s.top() >= 10)
				{
					cout << arr[s.top() - 10];
					s.pop();
				}
				else
				{
					cout << s.top();
					s.pop();
				}
			}
		}
	}

	return 0;
}