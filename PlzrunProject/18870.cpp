#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<int> v;
	vector<int> v2;
	map<int, int> m;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end());

	int size = v2.size();
	int cnt = 0;

	for (int i = 0; i < size; i++)
		if (m.find(v2[i]) == m.end())
			m.insert({ v2[i],cnt++ });

	for (int i = 0; i < v.size(); i++)
		cout << m.find(v[i])->second << ' ';

	return 0;
}