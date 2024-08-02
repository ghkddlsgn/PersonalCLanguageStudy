#pragma once
#include <iostream>
using namespace std;

class Point;
class PointCnt
{
private:
    int cnt = 0;
public:
    ~PointCnt()
    {
        cout<<"calculate count is "<<cnt<<endl;
    }
    Point PointAdder(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
};

class Point
{
private:
    int x,y;

public:
    Point(const int& xpos, const int& ypos):x(xpos), y(ypos){}
   
    friend Point PointCnt::PointAdder(const Point&, const Point&);
    friend Point PointCnt::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);
};

void ShowPointPos(const Point &pos)
{
    cout<<"x : "<<pos.x<<"y : "<<pos.y<<endl;
}