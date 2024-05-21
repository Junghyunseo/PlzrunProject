#include<iostream>

using namespace std;

int main(void) 
{
	cin.tie(0)->sync_with_stdio(0);

	int N, ans = 0;;

	cin >> N;
	ans = N / 5;
	if (N % 5)
		ans++;
	cout << ans;
	return 0;
}