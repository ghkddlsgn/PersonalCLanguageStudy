#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuBTree.h"

int main()
{
    InhuBTree Btree(3,1,2,3);
    Btree.PrintTree();
    std::cout << "Enter a value to delete: ";
    return 0;
}