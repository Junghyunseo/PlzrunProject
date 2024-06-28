#include<iostream>
#include<deque>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int num, X;
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 1)
		{
			cin >> X;
			dq.emplace_front(X);
		}
		else if (num == 2)
		{
			cin >> X;
			dq.emplace_back(X);
		}
		else if (num == 3)
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		else if (num == 4)
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		else if (num == 5)
			cout << dq.size() << '\n';
		else if (num == 6)
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if(num==7)
			if (!dq.empty())
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
		else
			if (!dq.empty())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
	}

	return 0;
}