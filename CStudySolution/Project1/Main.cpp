#include "Main.h"
#include <iostream>
#include <vector>
#include "DataStructure\Tree\InhuBTree.h"

int main()
{
    InhuBTree Btree(3);
    std::vector<int> numbers = {10,20,30,40,50,60,70,80,90,100,110};
    for(int i = 0; i < numbers.size(); i++) {
        std::cout << "Inserting " << numbers[i] << std::endl;
        Btree.AddNewValue(numbers[i]);

        Btree.PrintTree();
        std::cout << "--------------------------------" << std::endl;
    }
    std::cout<<"Enter a value to delete: ";
    return 0;
}