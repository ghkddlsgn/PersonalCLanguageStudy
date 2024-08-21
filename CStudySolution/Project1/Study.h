#pragma once

#include <iostream>
#include "CommonClass/CustomVector.h"

using namespace std;

int main()
{
    CustomVector<float> v;
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(50);
    v.PushBack(99);
    v.PopBack();
    v.Erase(2);

    CustomVector<float> w;
    w = v;

    for (int i = 0; i<w.Size(); i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    cout<<"Size : "<<v.Size()<<" Capacity : "<<v.Capacity()<<endl;
    return 0;
}