#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	queue<int> q;
	queue<int> q2;
	cin >> N;

	for (int i = 1; i < N + 1; i++)
		q.push(i);

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		q2.push(tmp);
		if (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		else
			break;
	}

	while (!q2.empty())
	{
		int tmp = q2.front();
		cout << tmp << ' ';
		q2.pop();
	}
	return 0;
}