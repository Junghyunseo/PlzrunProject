#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, ans;

	cin >> n;

	ans = n / 5 + n / 25 + n / 125;

	cout << ans;

	return 0;

}