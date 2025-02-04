#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuBTree.h"

int main()
{
    InhuBTree Btree(3);
    int numbers[] = {83, 31, 127, 15, 45, 92, 8, 62, 103, 55, 19, 71, 39, 144, 95, 
                    23, 67, 112, 41, 88, 5, 77, 134, 50, 99, 12, 82, 118, 35, 91,
                    27, 73, 142, 48, 96, 16, 64, 109, 38, 85, 3, 79, 124, 52, 97,
                    21, 69, 115, 43, 89};
    for(int i = 0; i < 50; i++) {
        std::cout << "Inserting " << numbers[i] << std::endl;
        Btree.AddNewValue(numbers[i]);
        Btree.PrintTree();
        std::cout << "--------------------------------" << std::endl;
    }
    std::cout<<"Enter a value to delete: ";
    return 0;
}