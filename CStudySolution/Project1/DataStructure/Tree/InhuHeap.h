#pragma once
#include <vector>

class InhuHeap
{
    private:
        std::vector<int> heap;
        int heapIndex = 0; //it include only heap range
    public:
        template <typename... Args>
        InhuHeap(Args... args)
        {
            heap.push_back(-1);
            (heap.push_back(args), ...);
            Sort_Heapify();
        }
        ~InhuHeap()
        {
            heap.clear();
        }
        int& operator[](int index)
        {
            return heap[index-1];
        }
        int GetHeapSize() const;
        void AddNewValue(int NewValue);
        void SortAsHeap();
        void Sort_Heapify();
        void DeleteValue();
        void PrintHeap() const;
};