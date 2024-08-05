#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int a=0, int b=0):x(a),y(b){}

    void ShowPointInfo()
    {
        cout<<"("<<x<<" "<<y<<")"<<endl;
    }

    Point& operator=(const Point& ref)
    {
        x = ref.x;
        y = ref.y;
        return *this;
    }
    
    friend ostream& operator<<(ostream & os,const Point & ref);
};

ostream& operator<<(ostream & os,const Point & ref)
{
    cout<<"("<<ref.x<<" "<<ref.y<<")";
    return os; 
}

typedef Point* POINT_PTR; 

class TArray
{
private:
    POINT_PTR * arr;
    int length;

    TArray& operator= (const TArray& ref){}
    TArray(const TArray&ref){}
    
public:
    TArray(int len):length(len)
    {
        arr = new POINT_PTR[len];
    }

    int adder(int a, int b);
    POINT_PTR& operator[](int index)
    {
        if (index <0 || length <length)
        {
            cout<<"Tried to access wrong index in Point arr"<<endl;
            exit(1);
        }

        return arr[index];
    }
    POINT_PTR& operator[](int index) const
    {
        if (index <0 || index < length)
        {
            cout<<"Tried to access wrong index in Point arr"<<endl;
            exit(1);
        }

        return arr[index];
    }

    ~TArray()
    {
        delete []arr;
    }
};

int main()
{
    TArray arr(5);
    for (int i = 0; i <5;i++)
    {
        arr[i] = new Point(i,i*2);
        cout<<*arr[i]<<endl;
    }

    for (int i = 0; i <5;i++)
    {
        delete []arr[i];
    }
    
    return 0;
}

//463