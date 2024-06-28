#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long N, fact = 1;
	cin >> N;


	for (int i = 1; i < N + 1; i++)
		fact *= i;
	cout << fact;
	return 0;
}