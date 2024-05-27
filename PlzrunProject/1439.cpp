#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int ans = 0;
	vector<string>zv;
	vector<string>ov;
	
	string tmpString = "";
	tmpString += s[0];
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			tmpString += s[i + 1];
		}
		else
		{
			if (s[i] == '1')
				ov.push_back(tmpString);
			else
				zv.push_back(tmpString);
			tmpString = "";
		}
	}
	if (s[s.size() - 2] == s[s.size() - 1])
		if (s[s.size() - 1] == '1')
			ov.push_back(tmpString);
		else
			zv.push_back(tmpString);
	else
		if (s[s.size() - 1] == '1')
			ov.push_back(tmpString);
		else
			zv.push_back(tmpString);

	if (zv.size() > ov.size())
		cout << ov.size();
	else
		cout << zv.size();
	return 0;
}