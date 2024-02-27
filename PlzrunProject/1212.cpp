#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0' && s.length() == 1)
		{
			cout << "0";
			break;
		}
		if (s[i] == '0')
		{
			if (i > 0)
				cout << "000";
		}
		else if (s[i] == '1')
		{
			if (i > 0)
				cout << "001";
			else
				cout << 1;
		}
		else if (s[i] == '2')
		{
			if (i > 0)
				cout << "010";
			else
				cout << 10;
		}
		else if (s[i] == '3')
		{
			if (i > 0)
				cout << "011";
			else
				cout << 11;
		}
		else if (s[i] == '4')
			cout << 100;
		else if (s[i] == '5')
			cout << 101;
		else if (s[i] == '6')
			cout << 110;
		else
			cout << 111;
	}

	return 0;
}