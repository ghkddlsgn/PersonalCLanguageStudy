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
    for(std::list<S_Path*>::const_iterator it = TargetElement.PathPtrArr.begin(); it != TargetElement.PathPtrArr.end(); it++)
    {
        ReturnValue.push_back(**it);
    }

    return ReturnValue;
}

int InhuGraph::GetOppositeElementIndex(const S_Path& TargetPath, const S_Element& TargetElement) const
{
    return Elements[TargetPath.Index1] == TargetElement ? TargetPath.Index2 : TargetPath.Index1;
}

void InhuGraph::Insert_Element(int Value)
{
    S_Element NewElement;
    NewElement.Value = Value;
    Elements.push_back(NewElement);
}

void InhuGraph::Insert_Path(int Index1, int Index2, int Cost)
{
    //valid index check
    if(Index1 >= Elements.size() || Index2 >= Elements.size())
    {
        std::cout<<"Insert_Path : Invalid index"<<std::endl;
        return;
    }

    Paths.push_front(S_Path(Index1, Index2, Cost));
    Elements[Index1].PathPtrArr.push_front(&Paths.front());
    Elements[Index2].PathPtrArr.push_front(&Paths.front());
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
    //valid check
    if (Elements.size() <= 1)
    {
        std::cout<<"There's no element to link"<<std::endl;
        return std::vector<int>();
    }

    //find smallest path cost and set init heads
    S_Element head1, head2;
    S_Path MinPath;

    std::vector<int> ReturnValue;
    std::vector<S_Element> LinkedElement;
    std::vector<S_Path> LinkedPath;
    LinkedElement.reserve(Elements.size());
    LinkedPath.reserve(Elements.size());

    for(auto it = Paths.begin(); it != Paths.end(); ++it)
    {
        S_Path CurrentPath = *it;
        if (CurrentPath.Cost < MinPath.Cost)
        {
            MinPath = CurrentPath;
            head1 = Elements[CurrentPath.Index1];
            head2 = Elements[CurrentPath.Index2];
        }
    }

    //store the init values
    LinkedPath.push_back(MinPath); 
    LinkedElement.push_back(head1);
    LinkedElement.push_back(head2);

    while(LinkedElement.size() < Elements.size())
    {
        int MinCost = INT_MAX; //reset min cost

        std::vector<S_Path> Paths_Total;
        std::vector<S_Path> Paths_Head1 = GetAllPathFromElement(head1);
        std::vector<S_Path> Paths_Head2 = GetAllPathFromElement(head2);
        Paths_Total.reserve(Paths_Head1.size() + Paths_Head2.size());

        /*
        add new path to Paths_Total
        inorder to figure out path is new, we need 2 filters
        */

        //filter 1 : already added element?
        for(int i = 0; i<Paths_Head1.size(); i++)
        {
            
            int OppositeIndex = GetOppositeElementIndex(Paths_Head1[i], head1);
            if(find<S_Element>(Elements[OppositeIndex], LinkedElement)) continue;
            
            Paths_Total.push_back(Paths_Head1[i]); //result of filter 1
        }
        for(int i = 0; i<Paths_Head2.size(); i++)
        {
            int OppositeIndex = GetOppositeElementIndex(Paths_Head2[i], head2);
            if(find<S_Element>(Elements[OppositeIndex], LinkedElement)) continue;
            
            Paths_Total.push_back(Paths_Head2[i]); //result of filter 1
        }
        
        //filter 2 : already added path?
        for(int i = Paths_Total.size() - 1; i >= 0; i--)
        {
            if(find<S_Path>(Paths_Total[i], LinkedPath))
            {
                Paths_Total.erase(Paths_Total.begin() + i); //if not pass filter 2, erase
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

        if (Paths_Total.size() == 0) //no path to add?
        {
            break; //if there's no path to add, that means all elements are linked
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
