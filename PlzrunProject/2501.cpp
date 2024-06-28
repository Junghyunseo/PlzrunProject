#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	vector<int> v;
	int y = 1;
	for (int i = 1; i < N + 1; i++)
		if (!(N % i))
			v.push_back(i);
	if (K <= v.size())
		cout << v[K - 1];
	else
		cout << 0;
	return 0;
}