#include "Study.h"

Point PointCnt::PointAdder(const Point& pnt1, const Point& pnt2)
{
    cnt++;
    return Point(pnt1.x+pnt2.x, pnt1.y+pnt2.y);
}

Point PointCnt::PointSub(const Point& pnt1, const Point& pnt2)
{
    cnt++;
    return Point(pnt1.x-pnt2.x, pnt1.y-pnt2.y);   
}

int main()
{
    Point a(1,2);
    Point b(3,4);
    PointCnt ct;

    ShowPointPos(ct.PointAdder(a,b));
    ShowPointPos(ct.PointAdder(b,a));

    return 0;

    
}