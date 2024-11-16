#pragma once
#include <iostream>
#include <limits>

#define EMPTY_INT -111111

class InhuCircularQueue
{
private:
    int * arr;
    int size = 0;
    int Start = -1;
    int End = -1;
protected:
    void AddIndex(int & Index) //use for +1 start, end
    {
        Index++;
        Index = Index%size;
    }
public:
    InhuCircularQueue(const int QueueLen) : size(QueueLen)
    {
        arr = new int[QueueLen];
    }
    template <typename... Args>
    InhuCircularQueue(const int QueueLen, Args... Elements) : size(QueueLen)
    {
        arr = new int[QueueLen];
        (AddNewElement(Elements), ...);
    }
    ~InhuCircularQueue()
    {
        delete []arr;
    }
    bool IsFull() const {return (End + 1)%size == Start;}
    bool IsEmpty() const {return Start==End;}

    void AddNewElement(int NewElement)
    {
        if (IsFull())
        {
            std::cout<<"Queue is full"<<std::endl;
            return;
        }
        AddIndex(End);
        arr[End] = NewElement;
    }
    int DeleteElement()
    {
        if (IsEmpty())
        {
            std::cout<<"Queue is empty"<<std::endl;
            return EMPTY_INT;
        }
        int ReturnValue;
        AddIndex(Start);
        ReturnValue = arr[Start];
        arr[Start] = EMPTY_INT;

        return ReturnValue;
    }

    void Print() const
    {
        std::cout<<"Queue List : ";
        for (int i = 0; i < size; i++)
        {
            std::cout<< arr[i] <<" ";
        }
        std::cout<<std::endl;
    }
};
