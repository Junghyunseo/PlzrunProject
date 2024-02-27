#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	char ch;
	stack<char> st;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		char undertop; // top 바로 아래에 있는 괄호
		ch = s[0];
		st.push(ch); // 우선 하나를 스택에 집어 넣기
		undertop = st.top();

		for (int j = 1; j < s.size(); j++)
		{
			if (st.empty())
			{
				ch = s[j];
				st.push(ch);
				undertop = st.top();
				continue;
			}

			undertop = st.top();
			ch = s[j];
			st.push(ch);

			char top = st.top();

			if (undertop == '(' && top == ')') // 스택에 넣을 때마다 맨 위와 그 아래를 확인
			{
				st.pop(); // 괄호가 완성되면 둘 다 빼기
				st.pop();
			}
		}

		if (st.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		while (!st.empty()) // 이걸 꼭 해줘야 함.
			st.pop();
	}

	return 0;
}