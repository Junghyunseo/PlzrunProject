#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long k, n;
	long long arr[10005];
	cin >> k >> n;
	long long num = 0;

	for (long long i = 0; i < k; i++)
		cin >> arr[i];

	sort(arr, arr + k);

	long long small = 1, middle, big = arr[k - 1];
	long long max = 0;

	while (1)
	{
		long long count = 0;
		middle = (small + big) / 2;
		//cout << small << ' ' << middle << ' ' << big << "!@#$" << '\n';

		num = 0; // ��������� ������ ���� �ʱ�ȭ

		for (long long i = 0; i < k; i++)
			num += arr[i] / middle; // middle¥�� ������ ���� ���ϱ�

		if (num >= n) // n�� �̻� ������� ��
		{
			if (max < middle) // n�� �̻� ���������, �� ���̰� �ִ��̸�
				max = middle;
			//cout << "max: " << max << '\n';

			small = middle; // �� ū ������ ������Ʈ
			middle = (small + big) / 2;
			//cout << "middle: " << middle << '\n';
		}
		else // n�� �̻� ��������� ���� ��
		{
			big = middle; // �� ���� ������ ������Ʈ
			middle = (small + big) / 2;
		}
		num = 0; 
		for (long long i = 0; i < k; i++)
			num += arr[i] / big; // big¥�� ������ ���� ���ϱ�
		if (num >= n)
			if (max < big)
				max = big;
		num = 0;
		for (long long i = 0; i < k; i++)
			num += arr[i] / small; // small¥�� ������ ���� ���ϱ�
		if (num >= n)
			if (max < small)
				max = small;

		if (small == middle || middle == big)
		{
			//if (count)
				break;
			count++;
		}
	}
	cout << max;

	return 0;
}