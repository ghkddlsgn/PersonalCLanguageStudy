#include "Project1/DataStructure/Graph/InhuGraph.h"
#include <iostream>
#include <queue>
#include <stack>

bool InhuGraph::Find(int FindValue, std::vector<int> TargetVector) const
{
    for (int i = 0; i < TargetVector.size(); i++)
    {
        if(FindValue == TargetVector[i])
        {
            return true;
        }
    }
    
    return false;
}

bool InhuGraph::Find(int FindValue, std::queue<int> TargetQueue) const
{
    while()
}


void InhuGraph::Insert(int Value, std::vector<int> AdjacentValues)
{
    //assume that AdjacentValues only containe valid values
    
    //add values to opponent elements
    for(int i = 0; i<elements.size(); i++)
    {
        for(int j = 0; j<AdjacentValues.size(); j++)
        {
            if(elements[i].front() == AdjacentValues[j])
            {
                elements[i].push_back(Value);
                break;
            }
        }
    }

    //make new list
    std::list<int> NewList = {Value};
    for(int i = 0; i<AdjacentValues.size(); i++)
    {
        NewList.push_back(AdjacentValues[i]);
    }
    elements.push_back(NewList);
}

void InhuGraph::Remove(int Value)
{
    for(int i = 0; i<elements.size(); i++)
    {
        if (elements[i].front() == Value) //is target value list?
        {
            elements.erase(elements.begin() + i);
            break;
        }

        //delete value that exist in opponent list
        std::list<int>::iterator it = elements[i].begin()++;
        while(it != elements[i].end())
        {
            if(*it == Value)
            {
                elements[i].erase(it);
                break;
            }
            it++;
        }
    }
}

std::vector<int> InhuGraph::Bfs(int StartValue) const
{
    std::queue<int> RemainElements; //element indices that i need to check
    std::vector<int> ReturnValue; //find out values

    //find start index from start value
    int StartIndex = -1;
    for(int i = 0; i<elements.size(); i++)
    {
        if (elements[i].front() == StartValue)
        {
            StartIndex = i;
            break;
        }
    }
    
    if (StartIndex == -1) //Start index is valid?
    {
        std::cout<<"there's no Value for "<<StartValue<<std::endl;
        return std::vector<int>();
    }

    int TargetIndex = StartIndex;
    while(ReturnValue.size() >= elements.size())
    {
        //check we already found this element
        int TargetValue = elements[TargetIndex].front();

        if(Find(TargetValue, ReturnValue)) //if we already found it, then skip to next
        {
            if(RemainElements.size() > 0)
            {
                TargetIndex = RemainElements.front();
                RemainElements.pop();
            }
            continue;
        }

        //add new values on RemainElements
        std::list<int>::const_iterator it = elements[TargetIndex].begin()++;
        while(it != elements[TargetIndex].end())
        {
            if(Find(*it, RemainElements))
        }

        ReturnValue.push_back(TargetValue);
    }
    
    return std::vector<int>();
}
