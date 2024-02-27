#include <iostream>
#include <vector>
#include <algorithm>
/// <summary>
/// substr 사용하는 방법도 있다.
/// </summary>

using namespace std;

int main(void)
{
	string s;
	vector<string> v;

	cin >> s;
	int size = s.size();

	for (int count = 0; count < size; count++)
	{
		v.push_back(s);
		s.erase(0, 1);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;

}