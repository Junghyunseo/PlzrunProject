#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int x, y, w, h, min = 1001;
	cin >> x >> y >> w >> h;

	if (w - x < min)
		min = w - x;
	if (x < min)
		min = x;
	if (h - y < min)
		min = h - y;
	if (y < min)
		min = y;
	cout << min;

	return 0;
}