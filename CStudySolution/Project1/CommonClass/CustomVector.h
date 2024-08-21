#pragma once
#include <vector>
#include <iostream>

const int DEFAULT_VECTOR_SIZE = 10;

template <typename T>
class CustomVector
{
private:
    int size;
    int capacity;
    T* elements;
public:
    CustomVector()
    {
        size = 0;
        capacity = DEFAULT_VECTOR_SIZE;
        elements = new T[DEFAULT_VECTOR_SIZE];
    }
    CustomVector(int n, const T& value)
    {
        size = n;
        capacity = n * 2;
        elements = new T[capacity];
        for (int i =-0; i<size; i++)
        {
            elements[i] = value;
        }
    }
    CustomVector(const CustomVector & ref)
    {
        size=ref.size;
        capacity=ref.capacity;
        elements= new T[capacity];
        for (int i = 0; i< size; i++)
        {
            elements[i] = ref[i];
        }
    }

    ~CustomVector()
    {
        delete[] elements;
    }

    int Size() const {return size;}
    int Capacity() const {return capacity;}
    bool IsEmpty() const {return size == 0;}

    T& operator[](int index)
    {
        return elements[index];
    }
    const T& operator[](int index) const
    {
        return elements[index];
    }
    CustomVector& operator =(const CustomVector & ref)
    {
        if(ref.size>size)
        {
            delete[] elements;
            capacity = ref.size*2;
            size = ref.size;
            elements = new T[capacity];
        }
        for (int i = 0; i<ref.size; i++)
        {
            elements[i] = ref.elements[i];
        }
        return *this;
    }
    
    void PushBack(const T object)
    {
        if (size == capacity)
        {
            T* newarr = new T[capacity*2];
            for (int i = 0; i<size; i++)
            {
                newarr[i] = elements[i];
            }
            delete[] elements;
            elements = newarr;
            capacity = capacity*2;
        }
        elements[size] = object;
        size++;
    }
    
    void PopBack()
    {
        if(size>0)
        {
            size--;
        }
    }
    void Erase(int index)
    {
        for (int i = index; i<size-1; i++)
        {
            elements[i] = elements[i+1];
        }
        size--;
    }
    void Insert(int index, T value)
    {
        if (size == capacity)
        {
            //if there's no memory, declare new ptr, and allocate more memory
            int NewCapacity = capacity*2;
            T* Newarr = new T[NewCapacity];

            //copy and paste values from old ptr to new ptr
            for (int i = 0; i <index-1; i++)
            {
                Newarr[i] = elements[i];
            }
            Newarr[index] = value;
            for (int i = index; i<size; i++)
            {
                Newarr[index + 1] = elements[i];
            }

            //delete old ptr and refresh private variables
            delete[] elements;
            elements = Newarr;
            capacity = NewCapacity;
        }
        else
        {
            //if we have enough memory, just insert the value in proper location and +1 other elements address
            for (int i = size; i == index; i--)
            {
                elements[i+1] = elements[i];
            }
            elements[index] = value;
        }
        size++;
    }
    void clear()
    {
        size = 0;
    }
};

template <typename T>
void PrintElements(std::vector<T> ref)
{
    std::cout<<"Vector Element : ";
    for (int i = 0; i < ref.size(); i++)
    {
        std::cout<<ref[i]<<", ";
    }
    std::cout<<std::endl;
}
