#pragma once
#include <iostream>
#include "Chain.h"

int HashChain::HashFunc(int Value)
{
    return Value%10;    
}

void HashChain::Insert(int Value)
{
    int InsertIndex = HashFunc(Value);
    std::list<int>& p = HashTable[InsertIndex];
    int cur = p.back();

    if (p.empty())
    {
        p.push_back(Value);
    }
    else
    {
        while(p.back())
        {

            p++;
        }
    }

void HashChain::Delete(int Value)
{
}

int HashChain::Search(int Value)
{
    return 0;
}
