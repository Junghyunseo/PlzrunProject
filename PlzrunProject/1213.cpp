#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	int arr[26]{};
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 'A']++;
	int oddCount = 0;
	int oddIndex = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] % 2)
		{
			oddCount++; // 홀수개인 알파벳 개수 세기
			oddIndex = i;
		}
	}
	if (oddCount < 2)
	{
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < arr[i] / 2; j++)
				cout << char(i + 'A');
		if (oddCount == 1)
			cout << char(oddIndex + 'A');
		for (int i = 26; i >= 0; i--)
			for (int j = 0; j < arr[i] / 2; j++)
				cout << char(i + 'A');
	}
	else
		cout << "I'm Sorry Hansoo";
	return 0;
}