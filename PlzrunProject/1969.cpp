#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T, S;
	cin >> T >> S;
	if ((T >= 12 && T <= 16) && (S == 0))
		cout << 320;
	else
		cout << 280;
	return 0;
}