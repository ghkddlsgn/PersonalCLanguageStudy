#include <iostream>
#include "Chain.h"

int HashChain::HashFunc(int Value) const
{
    return Value%10;    
}

void HashChain::Insert(int Value)
{
    int InsertIndex = HashFunc(Value);
    std::list<int>& p = HashTable[InsertIndex];
    std::list<int>::iterator it;

    if (p.empty())
    {
        p.push_back(Value);
    }
    else
    {
        it = p.begin();
        while(it != p.end())
        {
           if(Value <= *it)
           {
                p.insert(it, Value);
                return;
           }
           it++;
        }
        p.push_back(Value);
    }
}

bool HashChain::Delete(int Value)
{
    std::list<int>::iterator it = Search(Value);
    std::list<int>& bucket = HashTable[HashFunc(Value)];
    if (it == bucket.end())
    {
        return false;
    }
    bucket.erase(it);
    return true;
}

std::list<int>::iterator HashChain::Search(int Value)
{
    int SearchIndex = HashFunc(Value);
    std::list<int>& p = HashTable[SearchIndex];
    std::list<int>::iterator it;

    for (it = p.begin(); it != p.end(); ++it)
    {
        if (*it == Value)
        {
            return it;
        }
    }
    return p.end();
}

void HashChain::PrintChainList() const
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Table[" << i << "]: ";
        for (const auto& value : HashTable[i])  // Using range-based for loop
        {
            std::cout << value << " -> ";
        }
        std::cout << "nullptr" << std::endl;  // Shows end of chain
    }
}