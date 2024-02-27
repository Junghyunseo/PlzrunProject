#include <iostream>
////////////////////////////// 자료형 주의!!!
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t; // 테스트 케이스 개수
	long long arr[105];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;

	for (int i = 5; i < 101; i++)
		arr[i] = arr[i - 5] + arr[i - 1];
	cin >> t;

	int n;
	for (int i = 0; i < t; i++) // 테스트 케이스 수만큼 반복
	{
		cin >> n;
		cout << arr[n] << '\n';
	}

	return 0;
}