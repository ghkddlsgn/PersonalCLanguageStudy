#pragma once
#include <iostream>
#include <cstdlib>


template <typename T>
class Point
{
private:
    T x,y;
public:
    Point(T a = 0, T b= 0):x(a),y(b){}
    
    void SetValue(T a, T b)
    {
        x = a;
        y = b;
    }
    
    Point* operator->()
    {
        return this;
    }
    Point& operator*()
    {
        return *this;
    }
    Point operator+(const Point& ref) const
    {
        return Point(x + ref.x, y +ref.y);
    }
    Point& operator+=(const Point& ref)
    {
        x += ref.x;
        y += ref.y;
        return *this;
    }
    void PrintString()
    {
        std::cout<<"function Called"<< std::endl;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os ,const Point<U>& ref); 
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os ,const Point<T>& ref)
{
    os<<"("<<ref.x<<" "<<ref.y<<")";
    return os;
}

