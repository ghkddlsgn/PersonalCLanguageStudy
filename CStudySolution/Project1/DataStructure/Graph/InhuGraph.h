#pragma once
#include <list>
#include <vector>
#include <queue>

struct S_Path
{
    int Index1 = -1;
    int Index2 = -1;
    int Cost = -1;

    S_Path(int a, int b)
    {
        Index1 = a;
        Index2 = -1;
        Cost = b;
    }
    S_Path(int Index1, int Index2, int cost)
    :Index1(Index1), Index2(Index2), Cost(cost)
    {}
};

struct S_Element
{
    int Value;
    std::list<S_Path*> PathPtrArr;
};

class InhuGraph
{
private:
    std::vector<S_Element> Elements;
    std::list<S_Path> Paths;
protected:
    int GetElementIndexFromValue(int TargetValue) const;
    std::vector<S_Path> GetAllPathFromElement(const S_Element& TargetElement) const;
    template <typename T>
    bool find(T FindValue, std::vector<T> TargetVector)
    {
    for(int i = 0; i<TargetVector.size(); i++)
    {
        if (FindValue == TargetVector[i])
        {
            return true;
        }
    }
    return false;
    }
public:
    InhuGraph()
    {

    }
    
    void Insert(int Value, std::vector<int> AdjacentValues, std::vector<int> PathCosts);
    void Remove(int Value);
    std::vector<int> Bfs(int StartValue) const;
    std::vector<int> prim() const;
    void print();
};

bool find(int FindValue, std::vector<int> TargetVector);
bool Find(int FindValue, std::queue<int> TargetQueue);
