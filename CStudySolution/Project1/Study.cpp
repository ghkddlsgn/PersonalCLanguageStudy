#include <iostream>

using namespace std;

struct point
{
    int xpos;
    int ypos;

public:
    void MovePos(int x, int y)
    {
        xpos += x;
        ypos += y;
    }

    void AddPoint(point ptr)
    {
        xpos += ptr.xpos;
        ypos += ptr.ypos;
    }

    void ShowPosition() const
    {
        cout<<"("<<xpos<<" ,"<<ypos<<")"<<endl;
    }
};

int main()
{
    point pos1 = {12,4};
    point pos2 = {20, 30};

    pos1.MovePos(-7,10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    return 0;
}
