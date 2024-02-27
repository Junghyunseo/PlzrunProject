#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string s;

	while (getline(cin, s))
	{
		int arr[4] = { 0,0,0,0 }; // 소문자, 대문자, 숫자, 공백

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				arr[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				arr[1]++;
			else if (s[i] >= '0' && s[i] <= '9')
				arr[2]++;
			else
				arr[3]++;
		}
		for (int i = 0; i < 4; i++)
		{
			cout << arr[i];
			if (i < 3)
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}