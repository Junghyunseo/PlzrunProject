#include <iostream>
#include<math.h>
using namespace std;

void hanoi(int num)
{


	cout << "1 3" << '\n';



}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;

	cout << pow(2, N) - 1 << '\n';

	hanoi(N);

	return 0;
}