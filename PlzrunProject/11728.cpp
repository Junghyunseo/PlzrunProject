// 시간 초과
#include <iostream>

#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	int arr[1000001]{};
	int arr2[1000001]{};
	queue<int> q1;
	queue<int> q2;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		q1.push(n);
	}
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		q2.push(n);
	}

	while (!q1.empty() || !q2.empty())
	{
		if (q1.empty())
		{
			cout << q2.front() << ' ';
			q2.pop();
			continue;
		}
		else if (q2.empty())
		{
			cout << q1.front() << ' ';
			q1.pop();
			continue;
		}
		else if (q1.front() < q2.front())
		{
			cout << q1.front() << ' ';
			q1.pop();
		}
		else
		{
			cout << q2.front() << ' ';
			q2.pop();
		}
	}

	return 0;
}