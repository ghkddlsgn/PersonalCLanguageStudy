#pragma once
#include <list>

class HashChain
{
private:
    std::list<int> HashTable[10];
protected:
    int HashFunc(int Value) const;
public:
    template<typename... Args>
    HashChain(Args... Values)
    {
        (Insert(Values), ...);
    }
    void Insert(int Value);
    bool Delete(int Value);
    std::list<int>::iterator Search(int Value);
    void PrintChainList() const;
};