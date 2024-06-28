#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int A, B, X, N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> X;
		cout << A * (X - 1) + B << '\n';
	}
	return 0;
}