#include<iostream>

using namespace std;
int main(void)
{
	int A, B;
	int arr[1001]{};

	int num = 1;
	cin >> A >> B;

	for (int i = 1; i < 1001; )
	{
		for (int tmp = num; tmp > 0; tmp--)
		{
			arr[i++] = num;
			if (i == 1001)
				break;
		}
		num++;
	}
	/*for (int i = 1; i < 1001; i++)
		cout << arr[i]<<'\n';*/
	int sum = 0;
	for (int i = A; i < B + 1; i++)
		sum += arr[i];
	cout << sum;
	return 0;
}