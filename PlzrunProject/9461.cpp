#include <iostream>
////////////////////////////// �ڷ��� ����!!!
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t; // �׽�Ʈ ���̽� ����
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
	for (int i = 0; i < t; i++) // �׽�Ʈ ���̽� ����ŭ �ݺ�
	{
		cin >> n;
		cout << arr[n] << '\n';
	}

	return 0;
}