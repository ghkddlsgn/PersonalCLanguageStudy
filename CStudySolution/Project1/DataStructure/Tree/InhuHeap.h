#pragma once

class vector;

class InhuHeap
{
    private:
        std::vector<int> heap;
    public:
        template <typename... Args>
        InhuHeap(Args... args)
        {
            heap[0] = -1;
            (AddNewValue(args), ...);
        }
        ~InhuHeap()
        {
            heap.clear();
        }
        int& operator[](int index)
        {
            return heap[index-1];
        }
        void AddNewValue(int NewValue);
        void DeleteValue(int TargetValue);
        void PrintHeap() const;
};