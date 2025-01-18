#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuTree.h"

int main()
{
    InhuTree tree{547, 231, 834, 159, 423, 912, 67, 345, 756, 128,
                  492, 871, 34, 678, 143}; // Random unbalanced tree with 15 nodes
    std::cout << "program Start" << std::endl;
    std::cout << std::endl;
    tree.PrintTreeSideways(4);

    std::cout<<"Begin modify"<<std::endl;
    tree.BalanceTree(tree.GetRoot(), nullptr);
    // tree.LR_Rotation(nullptr, tree.GetRoot());
    // tree.PrintTreeSideways(4);
    std::cout << std::endl << "program End" << std::endl;
    return 0;
}