#include "InhuHeap.h"
#include <iostream>

int InhuHeap::GetHeapSize() const
{
    return heapIndex;
}


void InhuHeap::AddNewValue(int NewValue)
{
    heap.push_back(NewValue);
    SortAsHeap();
}


void InhuHeap::SortAsHeap()
{
    for (int i = heapIndex + 1; i < heap.size(); i++)
    {
        int NewValue = heap[i];
        int targetIndex = i;
        int parentIndex = targetIndex / 2;
        while(0 < parentIndex && heap[parentIndex] < NewValue)
        {
            heap[targetIndex] = heap[parentIndex];
            targetIndex = parentIndex;
            parentIndex = targetIndex / 2;
        }
        heap[targetIndex] = NewValue;
    }
    heapIndex = heap.size() - 1;
}

void InhuHeap::Sort_Heapify() //compare every node from the root
{
    //check valid : heap is empty?
    if (heap.size() <= 1)
    {
        return;
    }

    int R_Child_idx;
    int L_Child_idx;
    int ReplaceChildIdx;

    std::cout<<"tree structure before sort"<<std::endl;
    PrintHeap();
    std::cout<<std::endl;
    for (int i = heap.size()/2; i >= 1; i--) //from non-leaf
    {
        int TargetIndex = i;
        while(1)
        {
            R_Child_idx = TargetIndex * 2 + 1;
            L_Child_idx = TargetIndex * 2;
            
            //which child should i need to compare
            if ((L_Child_idx <= heap.size() - 1)) //Lchild is exist?
            {
                ReplaceChildIdx = L_Child_idx;
                if (R_Child_idx <= heap.size() - 1) //Rchild is exist too?
                {
                    ReplaceChildIdx = (heap[L_Child_idx] > heap[R_Child_idx]) ? L_Child_idx : R_Child_idx; //chose the bigger one
                }
            }
            else //if childs are not exist, then break;
            {
                break;
            }
            
            // do i need to swap? : target is smaller then child?
            if (heap[TargetIndex] < heap[ReplaceChildIdx]) 
            {
                //begin swap
                std::swap(heap[TargetIndex], heap[ReplaceChildIdx]);

                //update target index to child
                TargetIndex = ReplaceChildIdx;                    
            }
            else
            {
                //if no need to swap, end compare for TargetIndex
                break;
            }
        }

    }
}

void InhuHeap::DeleteValue()
{
    if (heap.size() <= 1)
    {
        std::cout<<"DeleteValue : heap is empty"<<std::endl;
        return;
    }
    
    //i can only delete root
    int ReplaceValue = heap.back();
    heap.pop_back();
    heapIndex--;

    if (heap.size() == 1) //if heap become empty, finish (there's no node to replace)
    {
        return;
    }
    
    //begin value replace
    int Replace_Target_Index = 1;
    //swap values until replaced value find proper node
    
    while(1)
    {
        heap[Replace_Target_Index] = ReplaceValue; //replace root as deleted value
        int L_Child_Index = Replace_Target_Index * 2;
        int R_Child_Index = Replace_Target_Index * 2 + 1;
        int Child_Index;
        
        //check child nodes are exist;
        if (R_Child_Index > heapIndex) //R node is not exist?
        {
            if (L_Child_Index > heapIndex) //L node is not exist too?
            {
                break; // end of swaping
            }
            else // only L node is exist?
            {
                Child_Index = L_Child_Index;
            }
        }
        else //both childs are exist
        {
            Child_Index = (heap[L_Child_Index] > heap[R_Child_Index]) ? L_Child_Index : R_Child_Index; 
        }
        
        if (heap[Child_Index] > ReplaceValue) //if child is more bigger, then begin swap
        {
            heap[Replace_Target_Index] = heap[Child_Index];
            Replace_Target_Index = Child_Index;
        }
        else //if child is small, end swapping
        {
            break;
        }
    }
}

void InhuHeap::PrintHeap() const
{
    if(heap.size() <= 1) {
        std::cout << "Empty heap" << std::endl;
        return;
    }

    int level = 0;
    int nodes_at_level = 1;
    int nodes_printed = 0;

    for(int i = 1; i < heap.size(); i++)
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