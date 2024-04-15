#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	map<string, int> m;
	map<int, string> m2;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		string tmp;
		cin >> tmp;
		m[tmp] = i;
		m2[i] = tmp;
	}

	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (m.find(tmp) != m.end())
			cout << m[tmp] << '\n';
		else
			cout << m2[stoi(tmp)] << '\n';
	}
	return 0;
}