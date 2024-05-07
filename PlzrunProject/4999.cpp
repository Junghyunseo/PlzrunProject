#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s1;
	string s2;
	cin >> s1 >> s2;
	if (s1.size() >= s2.size())
		cout << "go";
	else
		cout << "no";
	return 0;
}