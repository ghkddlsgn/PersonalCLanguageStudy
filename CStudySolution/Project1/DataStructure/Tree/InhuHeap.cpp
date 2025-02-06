#include "InhuHeap.h"
#include <iostream>
#include <vector>

void InhuHeap::AddNewValue(int NewValue)
{
    heap.push_back(NewValue);
    int targetIndex = heap.size();
    int parentIndex = targetIndex / 2;

    while(0 < parentIndex && heap[parentIndex] < NewValue)
    {
        heap[targetIndex] = heap[parentIndex];
        targetIndex = parentIndex;
        parentIndex = targetIndex / 2;
    }
    heap[parentIndex] = NewValue;
}

void InhuHeap::PrintHeap() const
{
    if(heap.empty()) {
        std::cout << "Empty heap" << std::endl;
        return;
    }

    int level = 0;
    int nodes_at_level = 1;
    int nodes_printed = 0;

    for(int i = 0; i < heap.size(); i++)
    {
        // Print indentation for tree structure
        if(nodes_printed == 0) {
            // Calculate and print leading spaces for this level
            int spaces = (1 << (4 - level)) - 1;
            for(int s = 0; s < spaces; s++) {
                std::cout << " ";
            }
        }

        std::cout << heap[i];
        nodes_printed++;

        // Add spaces between nodes at the same level
        if(nodes_printed < nodes_at_level && i < heap.size() - 1) {
            int spaces = (1 << (5 - level)) - 1;
            for(int s = 0; s < spaces; s++) {
                std::cout << " ";
            }
        }

        // Move to next level if current level is complete
        if(nodes_printed == nodes_at_level) {
            std::cout << std::endl;
            nodes_printed = 0;
            level++;
            nodes_at_level = 1 << level;
        }
    }
    
    if(nodes_printed > 0) 
    {
        std::cout << std::endl;
    }
}