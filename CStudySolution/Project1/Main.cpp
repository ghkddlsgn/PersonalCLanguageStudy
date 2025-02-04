#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuBTree.h"

int main()
{
    InhuBTree Btree(3);

    for (int i = 1; i<=15; i++)
    {
        std::cout<<"Add new value: "<<i<<std::endl;
        Btree.AddNewValue(i);
        Btree.PrintTree();
        std::cout<<"\n";
        std::cout<<"\n";
    }
    std::cout<<"Enter a value to delete: ";
    return 0;
}