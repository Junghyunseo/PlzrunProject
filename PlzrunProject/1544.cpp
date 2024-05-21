#include<iostream>
#include<vector>
using namespace std;

bool comp(string s1, string s2)
{
	bool isSame = false;
	if (s1.size() == s2.size())
	{
		for (int j = 0; j < s2.size(); j++)
		{
			int size = 0;
			for (int i = 0; i < s1.size(); i++)
			{
				if (s1[i] == s2[(j + i) % s2.size()])
					size++;
			}
			if (size == s1.size())
			{
				isSame = true;
				break;
			}
		}
	}
	return isSame;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	vector<string> vs;
	bool arr[51]{};
	cin >> N;
	int ans = N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		vs.push_back(tmp);
	}
	
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; i + j < N; j++)
		{
			if (!(arr[i]))
			{
				if (comp(vs[i], vs[i + j]))
				{
					ans--;
					arr[i + j] = true;
				}
			}
		}
	}
	cout << ans;
	return 0;
}