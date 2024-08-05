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
    Point& operator++()
    {
        x++;
        y++;
        return *this;
    }
    Point operator++(int)
    {
        const Point ReturnValue(x,y);
        x++;
        y++;
        return ReturnValue;
    }
    Point& operator--()
    {
        x--;
        y--;
        return *this;
    }
    Point operator*(int a) const
    {
        const Point ReturnValue(x*a, y*a);
        return ReturnValue;
    }
    const Point operator--(int)
    {
        const Point ReturnValue(*this);
        x--;
        y--;
        return ReturnValue;
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
    friend ostream& operator<<(ostream& os, const Point &pos);
    friend istream& operator>>(istream& is, Point &pos);
};

Point operator~(const Point &ref)
{
    return {~ref.x, ~ref.y};
}
Point operator*(int a, const Point &ref)
{
    Point returnValue(ref);
    return ref.operator*(a);
}
ostream& operator<<(ostream& os, const Point &pos)
{
    os<<"["<<pos.x<<" "<<pos.y<<"]";
    return os;
}
istream& operator>>(istream& is, Point &pos)
{
    is>>pos.x>>pos.y;

    return is;
}

int main()
{
    Point pt_A(10,20);

    cin>>pt_A;
    cout<<pt_A;
    
    return 0;
}