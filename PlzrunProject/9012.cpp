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
		char undertop; // top �ٷ� �Ʒ��� �ִ� ��ȣ
		ch = s[0];
		st.push(ch); // �켱 �ϳ��� ���ÿ� ���� �ֱ�
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

			if (undertop == '(' && top == ')') // ���ÿ� ���� ������ �� ���� �� �Ʒ��� Ȯ��
			{
				st.pop(); // ��ȣ�� �ϼ��Ǹ� �� �� ����
				st.pop();
			}
		}

		if (st.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		while (!st.empty()) // �̰� �� ����� ��.
			st.pop();
	}

	return 0;
}