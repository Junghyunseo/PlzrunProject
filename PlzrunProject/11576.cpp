#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int a, b, m;
	int dec = 0;
	int arr[30];
	stack<int> s;

	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) // 10진수로 바꾸기
		dec += arr[i] * pow(a, m - 1 - i);

	while (1)
	{
		if (dec < b)
		{
			s.push(dec);
			break;
		}
		else
		{
			s.push(dec % b);
			dec /= b;
		}
	}

	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}