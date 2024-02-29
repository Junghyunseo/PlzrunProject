#include <iostream>

using namespace std;

int main(void)
{
	int arr[5], sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	cout << sum;
	return 0;
}