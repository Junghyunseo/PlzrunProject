#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	
	int a;
	while (1)
	{
		cin >> a;
		if (!a)
			break;
		else
		{
			cout << a * (a + 1) / 2 << '\n';
		}
	}


	return 0;
}