#include<iostream>
#include<math.h>
#define M 1234567891
#define r 31

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	int L;
	long long sum = 0;
	long long mod[51]{};

	mod[0] = 1;
	for (int i = 1; i < 51; i++) // 31�� �ŵ�������� M�� mod ���� �����
		mod[i] = (mod[i - 1] * r % M) % M;
	cin >> L;
	cin >> s;

	for (int i = 0; i < L; i++)
	{
		sum += ((s[i] - 'a' + 1) * mod[i]) % M;
		sum %= M;
	}

	cout << sum;
	return 0;
}