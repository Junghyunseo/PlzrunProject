#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n1, k1, n2, k2;

	cin >> n1 >> k1 >> n2 >> k2;

	cout << n1 * k1 + n2 * k2;
	return 0;
}