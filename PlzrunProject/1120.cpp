#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string A, B;

	cin >> A >> B;
	int min = 100;
	for (int i = 0; i <= B.length() - A.length(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < A.length(); j++)
			if (A[j] != B[j + i])
				tmp++;
		if (min > tmp)
			min = tmp;
	}
	cout << min;

	return 0;
}