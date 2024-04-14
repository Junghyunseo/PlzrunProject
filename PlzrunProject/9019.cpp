#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>

using namespace std;

queue < pair<int, string>> q;
bool arr[10000]{};
int D(int n)
{
	return 2 * n % 10000;
}
int S(int n)
{
	if (n)
		return n - 1;
	else
		return 9999;
}
int L(int n)
{
	int d1 = n / 1000;
	int d2 = (n % 1000) / 100;
	int d3 = (n % 100) / 10;
	int d4 = n % 10;
	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}
int R(int n)
{
	int d1 = n / 1000;
	int d2 = (n % 1000) / 100;
	int d3 = (n % 100) / 10;
	int d4 = n % 10;
	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;

	for (int k = 0; k < T; k++)
	{
		int A, B;
		int check = 0;
		string ansS;
		cin >> A >> B;
		q.push({ A,"" });
		arr[A] = true;

		while (!q.empty())
		{
			int tmp = q.front().first;
			if (tmp == B)
			{
				ansS = q.front().second;
				break;
			}
			string tmpString = q.front().second;
			q.pop();
			if (!arr[D(tmp)])
			{
				q.push({ D(tmp), tmpString + "D" });
				arr[D(tmp)] = true;
			}
			if (!arr[S(tmp)])
			{
				q.push({ S(tmp), tmpString + "S" });
				arr[S(tmp)] = true;
			}
			if (!arr[L(tmp)])
			{
				q.push({ L(tmp), tmpString + "L" });
				arr[L(tmp)] = true;
			}
			if (!arr[R(tmp)])
			{
				q.push({ R(tmp), tmpString + "R" });
				arr[R(tmp)] = true;
			}
		}
		cout << ansS << '\n';

		while (!q.empty())
			q.pop();
		fill(arr, arr + 10000, false);
	}

	return 0;
}