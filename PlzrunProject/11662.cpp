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
		double abxDif = bx - ax; // ÁÂÇ¥°£ x,y Â÷ÀÌµé
		double abyDif = by - ay;
		double cdxDif = dx - cx;
		double cdyDif = dy - cy;

		double m1ax = ax + abxDif / 3; // m1aÀÇ xÁÂÇ¥
		double m1ay = ay + abyDif / 3; // m1aÀÇ yÁÂÇ¥
		double m2ax = ax + abxDif / 3 * 2; // m2aÀÇ xÁÂÇ¥
		double m2ay = ay + abyDif / 3 * 2; // m2aÀÇ yÁÂÇ¥
		
		double m1cx = cx + cdxDif / 3;
		double m1cy = cy + cdyDif / 3;
		double m2cx = cx + cdxDif / 3 * 2;
		double m2cy = cy + cdyDif / 3 * 2;

		if (dis(m1ax, m1cx, m1ay, m1cy) < dis(m2ax, m2cx, m2ay, m2cy))
		{
			if (min > dis(m1ax, m1cx, m1ay, m1cy)) // °Å¸® ÃÖ¼Ú°ª ¾÷µ¥ÀÌÆ®
			{
				min = dis(m1ax, m1cx, m1ay, m1cy);
			}
			bx = m2ax; // ÁÂÇ¥»ó ÀÛÀº ÂÊÀ¸·Î 2/3 ÁÙÀÌ±â
			by = m2ay;
			dx = m2cx;
			dy = m2cy;
		}
		else
		{
			if (min > dis(m2ax, m2cx, m2ay, m2cy))
				min = dis(m2ax, m2cx, m2ay, m2cy);
			ax = m1ax; // ÁÂÇ¥»ó Å« ÂÊÀ¸·Î 2/3 ÁÙÀÌ±â
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