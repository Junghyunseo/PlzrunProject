#include<iostream>
#include<math.h>

using namespace std;

double dis(double ax, double bx, double ay, double by)
{
	return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	double ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	double acDis = dis(ax, cx, ay, cy);
	double bdDis = dis(bx, dx, by, dy);

	int count = 0;
	double min = 20000;

	while (count < 100)
	{
		double abxDif = bx - ax; // ��ǥ�� x,y ���̵�
		double abyDif = by - ay;
		double cdxDif = dx - cx;
		double cdyDif = dy - cy;

		double m1ax = ax + abxDif / 3; // m1a�� x��ǥ
		double m1ay = ay + abyDif / 3; // m1a�� y��ǥ
		double m2ax = ax + abxDif / 3 * 2; // m2a�� x��ǥ
		double m2ay = ay + abyDif / 3 * 2; // m2a�� y��ǥ
		
		double m1cx = cx + cdxDif / 3;
		double m1cy = cy + cdyDif / 3;
		double m2cx = cx + cdxDif / 3 * 2;
		double m2cy = cy + cdyDif / 3 * 2;

		if (dis(m1ax, m1cx, m1ay, m1cy) < dis(m2ax, m2cx, m2ay, m2cy))
		{
			if (min > dis(m1ax, m1cx, m1ay, m1cy)) // �Ÿ� �ּڰ� ������Ʈ
			{
				min = dis(m1ax, m1cx, m1ay, m1cy);
			}
			bx = m2ax; // ��ǥ�� ���� ������ 2/3 ���̱�
			by = m2ay;
			dx = m2cx;
			dy = m2cy;
		}
		else
		{
			if (min > dis(m2ax, m2cx, m2ay, m2cy))
				min = dis(m2ax, m2cx, m2ay, m2cy);
			ax = m1ax; // ��ǥ�� ū ������ 2/3 ���̱�
			ay = m1ay;
			cx = m1cx;
			cy = m1cy;
		}
		count++;
	}
	cout << fixed;
	cout.precision(10);
	cout << min;

	return 0;
}