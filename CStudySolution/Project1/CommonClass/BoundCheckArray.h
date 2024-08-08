#pragma once

template <typename T=int>
class BoundCheckArray
{
private:
    T * arr;
    int length;

    BoundCheckArray(const BoundCheckArray& ref) {}
public:
    BoundCheckArray(int len) : length(len)
    {
        arr = new T[len];
    }
    BoundCheckArray& operator=(const BoundCheckArray<T>& ref)
    {
        if (&ref != this)
        {
            delete []arr;
        }
        length = ref.length;
        arr = new T[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = ref.arr[i];
        }
        return *this;
    }

    T& operator[](const int index) const
    {
        return arr[index];
    }
    T operator[](const int index)
    {
        return arr[index];
    }
    int GetArrlen() const
    {
        return length;
    }
    ~BoundCheckArray()
    {
        delete []arr;
    }
};
