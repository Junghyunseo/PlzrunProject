#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	char arr[5][15];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 15; j++)
			arr[i][j] = '*';

	string s;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 5; j++)
			if (arr[j][i] != '*')
				cout << arr[j][i];

	return 0;
}