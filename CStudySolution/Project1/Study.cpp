#include <iostream>
using namespace std;

class Point
{
private:
    int xpos = 0, ypos = 0;

public:
    Point(const int x, const int y)
    {
        xpos = x;
        ypos = y;
    }
};

class Rectangle
{
private:
    Point UpLeft, DownRight;

public:
    Rectangle(int x1, int y1, int x2, int y2):UpLeft(x1,y1), DownRight(x2, y2)
    {
        
    }

    
    
};

int main()
{
    return 0;
}