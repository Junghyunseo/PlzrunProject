#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s;
string tmpS;
vector<string> vs;

void split(int a, int b)
{
	for (int i = a; i >= 0; i--)
		tmpS.push_back(s[i]);

	for (int i = b; i > a; i--)
		tmpS.push_back(s[i]);

	for (int i = s.size() - 1; i > b; i--)
		tmpS.push_back(s[i]);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> s;

	for (int i = 0; i < s.size() - 2; i++)
	{
		for (int j = i + 1; j < s.size() - 1; j++)
		{
			split(i, j);
			vs.push_back(tmpS);
			tmpS.clear();
		}
	}

	sort(vs.begin(), vs.end());

	cout << vs[0];
	return 0;
}