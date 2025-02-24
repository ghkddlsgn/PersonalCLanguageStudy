#include "Project1/DataStructure/Graph/InhuGraph.h"
#include <iostream>
#include <stack>

bool Find(int FindValue, std::vector<int> TargetVector)
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

bool Find(int FindValue, std::queue<int> TargetQueue)
{
    while (!TargetQueue.empty())
    {
        if (FindValue == TargetQueue.front())
        {
            return true;
        }
        TargetQueue.pop();
    }
    return false;
}

int InhuGraph::GetElementIndexFromValue(int TargetValue) const
{
    for(int i = 0; i<Elements.size(); i++)
    {
        if (Elements[i].Value == TargetValue)
        {
            return i;
        }
    }

    std::cout<<"GetElementIndexFromValue : Invalid TargetValue Search"<<std::endl;
    return -1;
}

void InhuGraph::Insert(int Value, std::vector<int> AdjacentValues)
{
    //assume that AdjacentValues only containe valid values
    
    //make new list
    S_Element NewElement;
    NewElement.Value = Value;
    Elements.push_back(NewElement);
    int NewElementIndex = Elements.size() - 1;
    for(int i = 0; i<AdjacentValues.size(); i++)
    {
        if (Elements[i].Value == NewElement.Value)
        {
            continue;
        }

        int AdjacentElementIndex = GetElementIndexFromValue(AdjacentValues[i]);
        //add adjacentElement's ptr on element
        NewElement.AdjacentElementsIndexList.push_back(AdjacentElementIndex);

        //Add NewElement's ptr on AdjacentElement
        Elements[AdjacentElementIndex].AdjacentElementsIndexList.push_back(NewElementIndex);
    }
}

void InhuGraph::Remove(int Value)
{
    for (int i = 0; i < Elements.size(); i++)
    {
        if (Elements[i].Value == Value) // is target value list?
        {
            // Get adjacent element indices
            std::list<int>::iterator it = Elements[i].AdjacentElementsIndexList.begin();
            while (it != Elements[i].AdjacentElementsIndexList.end())
            {
                int opponentIndex = *it;
                // Remove target value's index from opponent element's adjacent list
                std::list<int>& opponentAdjList = Elements[opponentIndex].AdjacentElementsIndexList;
                opponentAdjList.remove(i);
                ++it;
            }
            // Remove the element itself from the graph
            Elements.erase(Elements.begin() + i);
            break;
        }
    }
}

std::vector<int> InhuGraph::Bfs(int StartValue) const
{
    std::queue<int> RemainElementsIndex; //element indices that i need to check
    std::vector<int> FinishedElementIndex;
    std::vector<int> ReturnValue; //find out values

    //find start index from start value
    RemainElementsIndex.push(GetElementIndexFromValue(StartValue));

    if (RemainElementsIndex.front() == -1) //Start index is valid?
    {
        std::cout<<"there's no Value for "<<StartValue<<std::endl;
        return std::vector<int>();
    }

    int TargetIndex;
    while(RemainElementsIndex.size() > 0)
    {
        //begin to search every adjacent element
        TargetIndex = RemainElementsIndex.front();

        //find every adjacent element and add to RemainElementIndex queue
        std::list<int> TargetList = Elements[TargetIndex].AdjacentElementsIndexList;
        std::list<int>::const_iterator it = TargetList.begin();
        while(it != TargetList.end())//prevent overlap
        {
            if (!Find(*it, FinishedElementIndex) && !Find(*it, RemainElementsIndex))//new value?
            {
                RemainElementsIndex.push(*it);
            }
            it++;
        }

        //move and store value for next loop
        RemainElementsIndex.pop();
        FinishedElementIndex.push_back(TargetIndex);
        ReturnValue.push_back(Elements[TargetIndex].Value);
    }
    return ReturnValue;
}
