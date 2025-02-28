#include "InhuGraph.h"
#include <iostream>
#include <stack>

bool find(int FindValue, std::vector<int> TargetVector)
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

std::vector<S_Path> InhuGraph::GetAllPathFromElement(const S_Element& TargetElement) const
{
    std::vector<S_Path> ReturnValue;
    std::list<S_Path*>::iterator it = TargetElement.PathPtrArr.front();
    while(it != TargetElement.PathPtrArr.end())
    {
        ReturnValue.push_back(**it);
    }
    return ReturnValue;
}


void InhuGraph::Insert(int Value, std::vector<int> AdjacentValues, std::vector<int> PathCosts)
{
    //assume that AdjacentValues only containe valid values
    //valid check
    if(AdjacentValues.size() != PathCosts.size())
    {
        std::cout<<"Insert : AdjacentValues and Pathcosts sizes are different"<<std::endl;
    }
    
    int Index1 = Elements.size() - 1; //index for new element

    //init for new Element
    S_Element NewElement;
    NewElement.Value = Value;
    for(int i = 0; i,AdjacentValues.size(); i++)
    {
        int Index2 = GetElementIndexFromValue(AdjacentValues[i]);
        //push new path data on variable : Paths
        Paths.push_front(S_Path(Index1, Index2, PathCosts[i]));

        //store New path data
        S_Path* NewPathPtr = &Paths.front();
        NewElement.PathPtrArr.push_back(NewPathPtr); //store at new lement
        Elements[Index2].PathPtrArr.push_front(NewPathPtr); //store at adjacent element
    }
    Elements.push_back(NewElement);
}

void InhuGraph::Remove(int Value)
{
    for (int i = 0; i < Elements.size(); i++)
    {
        if (Elements[i].Value == Value) // is target value list?
        {
            // Get adjacent element indices
            std::list<S_Path*>::iterator it = Elements[i].PathPtrArr.front();
            while (it != Elements[i].PathPtrArr.end())
            {
                S_Path OpponentInfo = *it;
                int opponentIndex = OpponentInfo.Index1;
                // Remove target value's index from opponent element's adjacent list
                std::list<S_Path>& opponentAdjList = Elements[opponentIndex].PathPtrArr;
                opponentAdjList.remove(i);
                ++it;
            }
            // Remove the element itself from the graph
            Elements.erase(Elements.begin() + i);
            break;
        }
    }

    std::cout<<"Remove : Invalid value"<<std::endl;
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
        std::list<S_Path> TargetList = *(Elements[TargetIndex].PathPtrArr);
        std::list<S_Path>::const_iterator it = TargetList.begin();
        while(it != TargetList.end())//prevent overlap
        {
            S_Path TargetInfo = *it;
            int Index1 = TargetInfo.Index1;
            if (!find(Index1, FinishedElementIndex) && !Find(Index1, RemainElementsIndex))//new value?
            {
                RemainElementsIndex.push(Index1);
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

std::vector<int> InhuGraph::prim() const
{
    //find smallest path cost
    S_Element head1;
    S_Element head2;
    int MinCost = -1;

    std::vector<S_Element> LinkedElement;
    std::vector<S_Path> LinkedPath;
    LinkedElement.resize(Elements.size());
    LinkedPath.resize(Elements.size());

    std::list<S_Path>::iterator it = Paths.front();
    for(int i = 0; i<Paths.size(); i++)
    {
        //need to find head and tail    
    }

    while(LinkedElement.size() < Elements.size())
    {
        std::vector<S_Path> PathsFromHeads;
        std::vector<S_Path> Head1Paths = GetAllPathFromElement(head1);
        std::vector<S_Path> Head2Paths = GetAllPathFromElement(head2);
        PathsFromHeads.resize(Head1Paths.size() + Head2Paths.size());

        //get all path from heads
        for(int i = 0; i<Head1Paths.size(); i++)
        {
            PathsFromHeads.push_back(Head1Paths[i]);
            PathsFromHeads.push_back(Head2Paths[i]);
        }
        
        //exclude path that head to already added element
        for(int i = 0; i<PathsFromHeads.size(); i++)
        {

            if(find<S_Element>(PathsFromHeads[i].Index1, LinkedElement))
        }
        //get the smallest cost path
    }
}
