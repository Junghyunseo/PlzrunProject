#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	int yo[5000];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		yo[i] = i + 1;
	yo[n] = '\n';

	cout << '<';

	int count = 0;
	int printCount = 0;

	for (int i = 0; ; i++) // printCout ���� = n �Ǹ� �ݺ��� Ż���ϵ���
	{
		if (yo[i] == 0) // �̰� �׳� �Ѿ��
			continue;
		else if (i == n) // ������ ���� �� �տ��� �ٽ� �����ϵ���
		{
			i = -1; // �̰� �ٽ��̾���,,
			continue;
		}
		else
			count++;

		if (count == k) // k��°���� ����ϱ�
		{
			if (printCount == n - 1)
				cout << yo[i] << ">";
			else
				cout << yo[i] << ", ";

			printCount++;
			count = 0;
			yo[i] = 0;
		}

		if (printCount == n)
			break;
	}

	return 0;
}