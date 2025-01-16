#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuTree.h"

int main()
{
    InhuTree tree{73, 15, 89, 42, 31, 67, 95, 8, 54, 23, 82, 47, 19, 63, 91};
    std::cout << "program Start" << std::endl;
    std::cout << std::endl;
    tree.PrintTreeSideways(4);
    std::cout << std::endl << "program End" << std::endl;

    return 0;
}