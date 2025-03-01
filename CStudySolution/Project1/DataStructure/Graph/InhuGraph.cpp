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
    std::list<S_Path*>::const_iterator it = TargetElement.PathPtrArr.begin();
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
    int TargetIndex = GetElementIndexFromValue(Value);

    if (TargetIndex == -1) //valid check
    {
        std::cout<<"Remove : Invalid value"<<std::endl;
        return;
    }

    // Get adjacent element indices
    std::list<S_Path*>::iterator it = Elements[TargetIndex].PathPtrArr.begin();
    while (it != Elements[TargetIndex].PathPtrArr.end())
    {
        int opponentIndex = (*it)->Index1 == TargetIndex ? (*it)->Index2 : (*it)->Index1;
        // Remove target value's index from opponent element's adjacent list
        std::list<S_Path*>& opponentAdjList = Elements[opponentIndex].PathPtrArr;
        opponentAdjList.remove(*it);
        ++it;
    }
    // Remove the element itself from the graph
    Elements.erase(Elements.begin() + TargetIndex);
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
        std::list<S_Path*> TargetList = Elements[TargetIndex].PathPtrArr;
        std::list<S_Path*>::iterator it = TargetList.begin();
        while(it != TargetList.end())//prevent overlap
        {
            int Index1 = (*it)->Index1;
            if (!find<int>(Index1, FinishedElementIndex) && !find<int>(Index1, RemainElementsIndex))//new value?
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
    //find smallest path cost and set init heads
    S_Element head1;
    S_Element head2;
    int MinCost = INT_MAX;

    std::vector<int> ReturnValue;
    std::vector<S_Element> LinkedElement;
    std::vector<S_Path> LinkedPath;
    LinkedElement.resize(Elements.size());
    LinkedPath.resize(Elements.size());

    std::list<S_Path>::const_iterator it = Paths.begin();
    for(int i = 0; i<Paths.size(); i++)
    {
        S_Path CurrentPath = *it;
        if (CurrentPath.Cost < MinCost)
        {
            MinCost = CurrentPath.Cost;
            head1 = Elements[CurrentPath.Index1];
            head2 = Elements[CurrentPath.Index2];
        }
        it++;
    }

    while(LinkedElement.size() < Elements.size())
    {
        std::vector<S_Path> Paths_Total;
        std::vector<S_Path> Paths_Head1 = GetAllPathFromElement(head1);
        std::vector<S_Path> Paths_Head2 = GetAllPathFromElement(head2);
        Paths_Total.resize(Paths_Head1.size() + Paths_Head2.size());

        MinCost = INT_MAX; //reset min cost
        S_Path MinPath;

        //get all path from heads
        for(int i = 0; i<Paths_Head1.size(); i++)
        {
            Paths_Total.push_back(Paths_Head1[i]);
            Paths_Total.push_back(Paths_Head2[i]);
        }
        
        //exclude path that head to already added element
        for(int i = 0; i<Paths_Total.size(); i++)
        {
            if(find<S_Element>(Elements[Paths_Total[i].Index1], LinkedElement))
            {
                Paths_Total.erase(Paths_Total.begin() + i);
            }
            if(find<S_Element>(Elements[Paths_Total[i].Index2], LinkedElement))
            {
                Paths_Total.erase(Paths_Total.begin() + i);
            }
        }

        //push previous heads to LinkedElement Array
        if(!find<S_Element>(head1, LinkedElement))
        {
            LinkedElement.push_back(head1);
        }
        if(!find<S_Element>(head2, LinkedElement))
        {
            LinkedElement.push_back(head2);
        }

        //find the smallest cost path and set new heads for next loop
        for(int i = 0; i<Paths_Total.size(); i++)
        {
            if(Paths_Total[i].Cost < MinCost)
            {
                MinCost = Paths_Total[i].Cost;
                MinPath = Paths_Total[i];
                head1 = Elements[Paths_Total[i].Index1];
                head2 = Elements[Paths_Total[i].Index2];
            }
        }

        LinkedPath.push_back(MinPath); //store the smallest cost path
    }

    for(int i = 0; i<LinkedElement.size(); i++)
    {
        ReturnValue.push_back(LinkedElement[i].Value);
    }
    return ReturnValue;
}
