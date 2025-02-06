#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuHeap.h"


int main()
{
    std::cout<<"begin programming"<<std::endl;

    InhuHeap heap(70,30,100,10,90,20,60,50,40,110,80);
    heap.PrintHeap();
    heap.SortAsHeap();
    heap.PrintHeap();

    std::cout<<"end programming"<<std::endl;
    return 0;

}