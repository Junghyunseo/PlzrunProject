#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	long long N, M;
	cin >> N >> M;
	if (N - M >= 0)
		cout << N - M;
	else
		cout << -1 * (N - M);
	return 0;
}