#include "Point.hpp"

#include <cstdio>

/* A utility function to calculate area of triangle formed by a(x1, y1), b(x2, y2) and c(x3, y3) */
Fixed area(const Point &a, const Point &b, const Point &c)
{
	return Fixed(
				(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
				(b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
				(c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
				)/2;
}

/* A function to check whether point P(x, y) lies inside the triangle formed by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	/* Calculate area of triangle ABC */
	Fixed A = area(a, b, c);

	/* Calculate area of triangle PAB */
	Fixed a1 = area(point, a, b);
	a1 = a1 < 0 ? a1 * -1 : a1;

	/* Calculate area of triangle PBC */ 
	Fixed a2 = area(point, b, c);
	a2 = a2 < 0 ? a2 * -1 : a2;

	/* Calculate area of triangle PAC */
	Fixed a3 = area(point, a, c);
	a3 = a3 < 0 ? a3 * -1 : a3;

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == a1 + a2 + a3);
}
