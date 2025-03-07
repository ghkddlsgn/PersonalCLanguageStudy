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

    S_Path()
    {
        Index1 = -1;
        Index2 = -1;
        Cost = 1000000;
    }

    bool operator==(const S_Path& other) const
    {
        if(Index1 == other.Index1 && Index2 == other.Index2 && Cost == other.Cost)
        {
            return true;
        }
        return false;
    }
};

struct S_Element
{
    int Value;
    std::list<S_Path*> PathPtrArr;

    bool operator==(const S_Element& other) const
    {
        if (Value == other.Value && PathPtrArr == other.PathPtrArr)
        {
            return true;
        }
        return false;
    }
};

class InhuGraph
{
private:
    std::vector<S_Element> Elements;
    std::list<S_Path> Paths;
protected:
    int GetElementIndexFromValue(int TargetValue) const;
    std::vector<S_Path> GetAllPathFromElement(const S_Element& TargetElement) const;
    int GetOppositeElementIndex(const S_Path& TargetPath, const S_Element& TargetElement) const;


    bool IsPathMakeCircle(std::vector<S_Path> linkedPaths) const;
    bool IsPathMakeCircle_Recursive(const std::vector<S_Path>& linkedPaths, std::vector<int>& visitedTimeMap, S_Path FromPath, int FromIndex) const;
    
    template <typename T>
    bool find(T FindValue, std::vector<T> TargetVector) const
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
    template <typename T>
    bool find(T FindValue, std::queue<T> TargetQueue) const
    {
        while(TargetQueue.size() > 0)
        {
            if (FindValue == TargetQueue.front())
            {
                return true;
            }
            TargetQueue.pop();
        }
        return false;
    }
public:
    InhuGraph()
    {

    }
    
    void Insert_Element(int Value);
    void Insert_Path(int Index1, int Index2, int Cost);
    void Remove(int Value);
    std::vector<int> Bfs(int StartValue) const;
    std::vector<int> prim_line() const;
    std::vector<S_Path> kruskal() const;
    std::vector<S_Path> kruskal_with_union() const;
    void print();
};
