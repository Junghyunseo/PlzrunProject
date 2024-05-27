#include<iostream>
#include<math.h>

using namespace std;

int N, r, c, ans = 0;
int printAns = 0;


int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> r >> c;
	int BM = 0;

	while (1)
	{

		if (r >= 0 && r < pow(2, N) / 4 && c >= 0 && c < pow(2, N) / 4)
		{
			BM = 0;
			ans += pow(2, N) / 4 * BM;
		}
		else if (r >= 0 && r < pow(2, N) / 4 && c >= pow(2, N) / 4)
		{
			BM = 1;
			ans += pow(2, N) / 4 * BM;
		}
		else if (r >= pow(2, N) / 4 && c >= 0 && c < pow(2, N) / 4)
		{
			BM = 2;
			ans += pow(2, N) / 4 * BM;
		}
		else
		{
			BM = 3;
			ans += pow(2, N) / 4 * BM;
		}
	}

	return 0;
}