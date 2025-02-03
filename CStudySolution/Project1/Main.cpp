#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuBTree.h"

int main()
{
    InhuBTree Btree(3,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    Btree.PrintTree();
    std::cout << "Enter a value to delete: ";
    return 0;
}