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

	for (int i = 0; ; i++) // printCout 개수 = n 되면 반복문 탈출하도록
	{
		if (yo[i] == 0) // 이건 그냥 넘어가기
			continue;
		else if (i == n) // 끝까지 오면 맨 앞에서 다시 시작하도록
		{
			i = -1; // 이게 핵심이었다,,
			continue;
		}
		else
			count++;

		if (count == k) // k번째마다 출력하기
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