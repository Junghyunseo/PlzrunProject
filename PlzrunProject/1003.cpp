#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;

	long long dpZero[51];
	long long dpOne[51];

	dpZero[0] = 1;
	dpZero[1] = 0;
	dpOne[0] = 0;
	dpOne[1] = 1;
	for (int i = 2; i < 51; i++)
	{
		dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
		dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
	}

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << dpZero[N] << ' ' << dpOne[N] << '\n';
	}

	return 0;
}