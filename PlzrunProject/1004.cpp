#include<iostream>
#include<math.h>
using namespace std;

int dis2(int ax, int ay, int bx, int by)
{
	return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}

bool isInTheCircle(int x,int y, int cx, int cy,int r) // 점의 좌표, 원의 중심의 좌표, 원의 반지름
{
	if (dis2(x, y, cx, cy) < r) // 원 안에 점이 있을 때
		return true;
	else
		return false;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int T;
	int x1, y1, x2, y2;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int ans = 0;
		int N, cx, cy, r;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> cx >> cy >> r;
			if (isInTheCircle(x1, y1, cx, cy, r))
				ans++;
			if (isInTheCircle(x2, y2, cx, cy, r))
				ans++;
			if (isInTheCircle(x1, y1, cx, cy, r) && isInTheCircle(x2, y2, cx, cy, r)) // 출발점, 도착점이 같은 원 안에 있으면 카운트 안 함.
				ans -= 2;
		}
		cout << ans << '\n';
	}

	return 0;
}