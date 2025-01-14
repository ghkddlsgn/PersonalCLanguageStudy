#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuTree.h"

int main()
{
    InhuTree tree;
    std::cout<<"program Start"<<std::endl;
    tree.AddNewNode(1);
    tree.PrintTreeNode(tree.GetRoot());
    std::cout<<"program End"<<std::endl;

    return 0;
}