#include<iostream>
#include<algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, A[50]{}, B[50]{};
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, A + N, comp);
	sort(B, B + N);

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];
	cout << sum;

	return 0;
}