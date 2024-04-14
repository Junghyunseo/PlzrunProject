// set을 이용한 풀이
//#include<iostream>
//#include<map>
//#include<string>
//#include<set>
//
//using namespace std;
//
//int main(void)
//{
//	cin.tie(0)->sync_with_stdio();
//	set<string> sett;
//	std::string s;
//	cin >> s;
//	int cnt = 0;
//
//	for (int i = 1; i <= s.size(); i++)
//	{
//		string tmp = "";
//		for (int j = 0; i + j <= s.size(); j++)
//		{
//			tmp = s.substr(j, i);
//			sett.insert(tmp);
//			cnt++;
//		}
//	}
//	cout << sett.size();
//
//	return 0;
//}
#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio();
	map<string, int> m;
	std::string s;
	cin >> s;
	int cnt = 0;

	for (int i = 1; i <= s.size(); i++)
	{
		string tmp = "";
		for (int j = 0; i + j <= s.size(); j++)
		{
			tmp = s.substr(j, i);	
			m.insert({ tmp, i });
			cnt++;
		}
	}
	cout << m.size();

	return 0;
}