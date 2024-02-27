#include <iostream>
#include <queue>

using namespace std;


int main(void)
{
	int n, index = 0;
	queue<int> q;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		string command;

		cin >> command;

		if (command == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}