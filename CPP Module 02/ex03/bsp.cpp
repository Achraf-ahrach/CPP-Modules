#include "Point.hpp"

static float area(Point const p1, Point const p2, Point const p3)
{
    float   area;

    //Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
    area =	(( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) )
			+ ( p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) )
			+ ( p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) )
			) / 2;

    if (area >= 0)
        return (area);
    else
        return (area * -1);
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   area_0, area_1, area_2, area_3;

    area_0 = area(a, b, c);
    area_1 = area(point, a, b);
    area_2 = area(point, b, c);
    area_3 = area(point, a, c);

    //  if the point is a vertex or on edge
    if (area_1 == 0 || area_2 == 0 || area_3 == 0)
        return (false);
    else if ((area_1 + area_2 + area_3) == area_0)
        return (true);
    else
        return (false);
}