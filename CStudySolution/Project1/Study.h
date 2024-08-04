#pragma once

#include <iostream>
using namespace std;

class Point
{
private:
    int x = 0, y = 0;
public:
    Point(int xpos, int ypos):x(xpos), y(ypos){}
    Point(){}

    Point operator-() const
    {
        return {-x, -y};
    }

    Point operator+(const Point &ref) const
    {
        return {x+ref.x,y+ref.y};
    }
    Point operator-(const Point &ref)
    {
        return {x-ref.x, y-ref.y};
    }
    Point& operator+=(const Point &ref)
    {
        x = x+ref.x;
        y = y+ref.y;
        
        return *this;
    }
    Point& operator-=(const Point &ref)
    {
        x = x-ref.x;
        y = y-ref.y;

        return *this;
    }
    bool operator==(const Point &ref) const
    {
        if (x == ref.x && y == ref.y)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const Point &ref) const
    {
        return !operator==(ref);
    }
    
    void ShowPosition() const
    {
        cout<<"{"<<x<<" "<<y<<"}"<<endl;
    }

    friend Point operator~(const Point &ref);
    
};

Point operator~(const Point &ref)
{
    return {~ref.x, ~ref.y};
}

int main()
{
    Point a(10,20);
    Point b(30,40);
    Point c;

    c+=b;

    a.ShowPosition();
    b.ShowPosition();
    c.ShowPosition();

    cout<<"Begin sub a-b"<<endl;

    c = a-b;
    c.ShowPosition();

    return 0;
}