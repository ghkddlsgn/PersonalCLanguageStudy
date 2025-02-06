#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuHeap.h"


int main()
{
    std::cout<<"begin programming"<<std::endl;

    InhuHeap heap(70,30,100,10,90,20,60,50,40,110,80);
    heap.PrintHeap();

    for (int i = 1; i < heap.GetHeapSize(); i++)
    {
        std::cout<<"Delete Attempt : "<<i<<std::endl;
        heap.DeleteValue();
        heap.PrintHeap();
    }
    std::cout<<"end programming"<<std::endl;
    return 0;
}