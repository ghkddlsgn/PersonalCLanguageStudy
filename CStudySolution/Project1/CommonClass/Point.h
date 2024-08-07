#pragma once
#include <iostream>
#include <cstdlib>



class Point
{
private:
    int x,y;
public:
    Point(int a = 0, int b= 0):x(a),y(b){}
    
    void * operator new(size_t size)
    {
        void * ptr = new char[size];
        return ptr;
    }
    void SetValue(int a, int b)
    {
        x = a;
        y = b;
    }
    void operator delete(void* adr)
    {
        delete []((char*)adr);
    }
    Point* operator->()
    {
        return this;
    }
    Point& operator*()
    {
        return *this;
    }
    void PrintString()
    {
        std::cout<<"function Called"<< std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& os ,const Point& ref); 
};

inline std::ostream& operator<<(std::ostream& os ,const Point& ref)
{
    std::cout<<"("<<ref.x<<" "<<ref.y<<")";
    return os;
}