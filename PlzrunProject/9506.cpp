#include<iostream>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);


	int n;
	int sum;
	queue < int> q;
	while (1)
	{
		sum = 0;
		cin >> n;
		if (n == -1)
			break;
		for (int i = 1; i < n; i++)
			if (!(n % i))
				sum += i;
		if (sum == n)
		{
			for (int i = 1; i < n; i++)
				if (!(n % i))
					q.push(i);
			cout << n << " = ";
			while (!q.empty())
			{
				if (q.size() != 1)
					cout << q.front() << " + ";
				else
					cout << q.front();
				q.pop();
			}
		}
		else
			cout << n << " is NOT perfect.";
		cout << '\n';
	}

	return 0;
}