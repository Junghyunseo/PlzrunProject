#include <iostream>

using namespace std;

int main(void)
{
	int a, b;

	cin >> a >> b;

	int M = 1, m;

	for (int i = 1; i <= a || i <= b; i++) // �ִ����� ���ϱ�
		if ((!(a % i) && !(b % i)))
			M = i;

	m = a * b / M;

	cout << M << '\n' << m;

	return 0;
}