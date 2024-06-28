#include <iostream>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	stack<int> s;

	cin >> N;
	int act, num;
	for (int i = 0; i < N; i++)
	{
		cin >> act;
		if (act == 1)
		{
			cin >> num;
			s.push(num);
		}
		else if (act == 2)
		{
			if (!s.empty())
			{
				int tmp = s.top();
				cout << tmp << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (act == 3)
			cout << s.size() <<'\n';
		else if (act == 4)
			if (s.empty())
				cout << 1 << '\n';
			else cout << 0 << '\n';
		else
			if (!s.empty())
			{
				int tmp = s.top();
				cout << tmp << '\n';
			}
			else
				cout << -1 << '\n';
	}
	return 0;
}