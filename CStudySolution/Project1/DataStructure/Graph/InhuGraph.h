#pragma once
#include <list>
#include <vector>
#include <queue>

struct S_Element
{
    int Value;
    std::list<int> AdjacentElementsIndexList;
};

class InhuGraph
{
private:
    std::vector<S_Element> Elements;
protected:
    int GetElementIndexFromValue(int TargetValue) const;
public:
    InhuGraph()
    {

    }
    
    void Insert(int Value, std::vector<int> AdjacentValues);
    void Remove(int Value);
    std::vector<int> Bfs(int StartValue) const;
    void print();
};

bool Find(int FindValue, std::vector<int> TargetVector);
bool Find(int FindValue, std::queue<int> TargetQueue);