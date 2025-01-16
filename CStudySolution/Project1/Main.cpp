#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuTree.h"

int main()
{
    InhuTree tree{50,30,60,20,40,35}; // Creates a tree that needs RL rotation
    // tree.BalanceTree(tree.GetRoot());
    std::cout << "program Start" << std::endl;
    std::cout << std::endl;
    tree.PrintTreeSideways(4);

    std::cout<<"Begin modify"<<std::endl;
    tree.RL_Rotation(nullptr, tree.GetRoot(), tree.GetRoot()->LNode, tree.GetRoot()->LNode->RNode);
    tree.PrintTreeSideways(4);
    std::cout << std::endl << "program End" << std::endl;
    return 0;
}