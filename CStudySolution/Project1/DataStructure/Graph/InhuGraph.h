#pragma once
#include <list>
#include <vector>
#include <queue>

class InhuGraph
{
private:
    std::vector<std::list<int>> elements;
public:
    InhuGraph()
    {

    }
    
    bool Find(int FindValue, std::vector<int> TargetVector) const;
    bool Find(int FindValue, std::queue<int> TargetQueue) const;
    void Insert(int Value, std::vector<int> AdjacentValues);
    void Remove(int Value);
    std::vector<int> Bfs(int StartValue) const;
    void print();
};