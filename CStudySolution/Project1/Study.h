#pragma once
#include <iostream>
#include <cstdlib>
#include "CommonClass/Point.h"

using namespace std;

class Sptr
{
private:
    Point * ptr;
public:
    Sptr()
    {
        ptr = new Point;
    }
    Point* operator ->()
    {
        return ptr; 
    }
    Point& operator *()
    {
        return *ptr;
    }
    ~Sptr()
    {
        delete ptr;
    }
};



int main()
{
    Sptr ptr;
    ptr->SetValue(100, 100);
    
    cout<<*ptr<<endl;
    
    return 0;
}