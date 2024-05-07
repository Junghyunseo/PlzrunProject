#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int max = 0;

	// Â¦¼ö Æç¸°µå·Ò
	for (int i = 0; i < s.size() - 1; i++)
	{
		bool isSame = true;
		int num = 0;
		int cntJ = 0;
		for (int j = 0; i - j >= 0 && i + j + 1 < s.size(); j++)
		{
			if (s[i - j] != s[i + j + 1])
			{
				isSame = false;
				num = 0;
				break;
			}
			cntJ++;
		}
		if (isSame && i + cntJ== s.size()-1)
			num = 2 * cntJ;
		if (max < num)
			max = num;
	}

	// È¦¼ö Æç¸°µå·Ò
	for (int i = 0; i < s.size() - 1; i++)
	{
		bool isSame = true;
		int num = 0;
		int cntJ = 0;
		for (int j = 0; i - j >= 0 && i + j + 2 < s.size(); j++)
		{
			cntJ++;
			if (s[i - j] != s[i + j + 2])
			{
				isSame = false;
				num = 0;
				break;
			}
		}
		if (isSame && i + cntJ + 1 == s.size() - 1)
			num = 2 * cntJ + 1;
		if (max < num)
			max = num;
	}
	if (max > 0)
		cout << 2 * s.size() - max;
	else
		cout << 2 * s.size() - max - 1;
	return 0;
}