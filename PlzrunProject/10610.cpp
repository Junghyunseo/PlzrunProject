#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	bool isZero = false;
	long long sum = 0;
	int arr[10]{};
	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] == '0')
			isZero = true;
		sum += N[i] - '0';
		arr[N[i] - '0']++; // 해당 숫자가 있음을 표시
	}

	if ((!isZero) || (sum % 3)) // 0이 안 들어있거나 각 자리 숫자의 합이 3의 배수가 아니면
		cout << -1;
	else
		for (int i = 9; i > -1; i--)
			for (int j = arr[i]; j > 0; j--)
				cout << i;
	return 0;
}