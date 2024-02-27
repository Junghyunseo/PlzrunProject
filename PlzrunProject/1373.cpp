#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	string s2;
	stack<long long> st;

	int pow[3] = { 1,2,4 };

	cin >> s;

	long long len = s.length();

	while (1)
	{
		int num = 0;
		for (long long j = 0; j < 3; j++)
		{
			if (len - 1 - j < 0)
			{
				len = 0;
				break;
			}
			num += (pow[j] * (s[len - 1 - j] - 48));
		}

		st.push(num);
		len -= 3;
		if (len <= 0)
			break;
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	return 0;
}