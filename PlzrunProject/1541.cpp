#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	int ans = 0;
	cin >> s;
	vector<string> vs;

	string tmp = "";
	bool isNeg = false;
	bool isFirst = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '+' && s[i] != '-')
			tmp += s[i];
		else
		{
			if (isFirst)
			{
				ans += stoi(tmp);
				isFirst = false;
			}
			else
			{
				if (isNeg)
					ans -= stoi(tmp);
				else
					ans += stoi(tmp);
			}
			tmp = "";
		}
		if (s[i] == '-')
			isNeg = true;
	}
	if (isNeg)
		ans -= stoi(tmp);
	else
		ans += stoi(tmp);
	cout << ans;
	return 0;
}