#pragma once
#include <list>
#include <vector>

class InhuGraph
{
private:
    std::vector<std::list<int>> elements;
public:
    InhuGraph()
    {

    }
    
    void Insert(int Value, std::vector<int> AdjacentValues);
    void Remove(int Value);
    std::list<int> Bfs(int Value) const;
    void print();
};