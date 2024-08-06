#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheck1DIntArray
{
private:
    int *arr;
    int length;
public:
    BoundCheck1DIntArray():length(-1)
    {
        arr = nullptr;
    }
    BoundCheck1DIntArray(int len) : length(len)
    {
        arr = new int[len];
    }
    BoundCheck1DIntArray(const BoundCheck1DIntArray& ref) : length(ref.length)
    {
        delete []arr;
        arr = new int[length];
    }
    BoundCheck1DIntArray & operator=(const BoundCheck1DIntArray& ref)
    {
        delete []arr;
        length = ref.length;
        arr = new int[length];
        return *this;
    }

    int& operator[](int index) const
    {
        return arr[index];
    }

    // ostream& operator<<(ostream& os, BoundCheck1DIntArray & ref)
    // {
    //     cout<<
    //     return os;
    // }
    
    void ResizeArray(int NewLen)
    {
        delete []arr;
        length = NewLen;
        arr = new int[NewLen];
    }
    void SetValue(int index, int Value)
    {
        if (index<0 && length<index)
        {
            cout<<"tried to access wrong address in SetValue function, access index is : "<<index<<endl;
            exit(1);
        }
        arr[index] = Value;
    }
    ~BoundCheck1DIntArray()
    {
        delete []arr;
    }
};

class BoundCheck2DIntArray
{
private:
    BoundCheck1DIntArray * Arr1D;
    int length_1DArray;
    int length_2DArray;
public:
    BoundCheck2DIntArray(int len_x, int len_y) : length_1DArray(len_x), length_2DArray(len_y)
    {
        Arr1D = new BoundCheck1DIntArray[length_2DArray];
        for (int i = 0; i <length_2DArray; i++)
        {
            Arr1D[i] = BoundCheck1DIntArray(len_x);
            for (int j = 0; j <length_1DArray; j++)
            {
                Arr1D[i].SetValue(j, i*j);
            }
        }
    }
    BoundCheck2DIntArray(const BoundCheck2DIntArray & ref)
    {
        BoundCheck2DIntArray(ref.length_1DArray, ref.length_2DArray);
    }
    BoundCheck1DIntArray& operator[] (int index) const
    {
        return Arr1D[index];
    }
    BoundCheck2DIntArray& operator= (const BoundCheck2DIntArray & ref)
    {
        delete []Arr1D;
        BoundCheck2DIntArray(ref.length_1DArray, ref.length_2DArray);
        return *this;
    }

    void ShowElment() const
    {
        for (int i = 0; i < length_2DArray; i++)
        {
            cout<<i<<"st line : ";
            for (int j = 0; j < length_1DArray; j++)
            {
                cout<<Arr1D[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    ~BoundCheck2DIntArray()
    {
        delete []Arr1D;
    }
};

int main()
{
    BoundCheck2DIntArray Arr(5,5);
    Arr.ShowElment();

    for(int i=0; i<5;i++)
    {
        for(int j=0; j<5; j++)
        {
            Arr[i][j] = 10*i*j;
        }
    }
    cout<<"After input"<<endl;
    Arr.ShowElment();
    
    return 0;
}