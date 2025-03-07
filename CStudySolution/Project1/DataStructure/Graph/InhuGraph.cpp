#include "InhuGraph.h"
#include <iostream>
#include <stack>

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

//check linkedpaths make circle
bool InhuGraph::IsPathMakeCircle(std::vector<S_Path> TargetPaths) const
{
    //this recored remain paths that not searched. if link is disconnected, it won't be searched in one recursive
    std::vector<S_Path> remainPaths = TargetPaths;
    //it record how many times the Paths are visited, if it's not circling, every element should be 1 at the end of search
    std::vector<int> visitedTimeMap;
    
    while(!remainPaths.empty())
    {
        visitedTimeMap.resize(remainPaths.size(), 0);

        S_Path StartPath = remainPaths[0];
        int head1 = StartPath.Index1;
        int head2 = StartPath.Index2;
        //begin search from the path both direction
        bool result1 = IsPathMakeCircle_Recursive(remainPaths, visitedTimeMap, StartPath, head1);
        bool result2 = IsPathMakeCircle_Recursive(remainPaths, visitedTimeMap, StartPath, head2);

        if(result1||result2) //if we found there's an circle in this loop, we don't need to search anymore
        {
            return true;
        }

        for(int i = remainPaths.size() - 1; i >= 0; i--) //find out is there any unsearched path bc it's not connected
        {
            if(visitedTimeMap[i] == 1) //remove already searched path
            {
                remainPaths.erase(remainPaths.begin() + i); // it will contain only unsearched paths
            }
        }
    }
    return false;
}

bool InhuGraph::IsPathMakeCircle_Recursive(const std::vector<S_Path>& linkedPaths, std::vector<int>& visitedTimeMap, S_Path FromPath, int FromIndex) const
{
    int FromIdx = FromPath.Index1 == FromIndex ? FromPath.Index2 : FromPath.Index1;
    int ToIdx;

    for(int i = 0; i<linkedPaths.size(); i++)
    {
        if ((linkedPaths[i].Index1 == FromIdx || linkedPaths[i].Index2 == FromIdx) && linkedPaths[i] != FromPath)
        {
            //find paths that connected with current head
            visitedTimeMap[i]++;
            ToIdx = linkedPaths[i].Index1 == FromIdx ? linkedPaths[i].Index2 : linkedPaths[i].Index1;
            if (visitedTimeMap[i] > 1) //i visited the same path more than once?
            {
                return true; //that means the graph is circling
            }
            //find deeper paths from current path
            if (IsPathMakeCircle_Recursive(linkedPaths, visitedTimeMap, linkedPaths[i], ToIdx))
            {
                return true;
            }
        }
    }
    return false; //if search finished without find circling, it's not circling at this search branch
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

std::vector<int> InhuGraph::prim_line() const
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

std::vector<S_Path> InhuGraph::kruskal() const
{
    if(Elements.size() <= 1)
    {
        std::cout<<"There's no element to link"<<std::endl;
        return std::vector<S_Path>();
    }

    int MaxSize = Elements.size() - 1; //How much paths can be linked?
    std::vector<S_Path> RemainPaths;
    std::vector<S_Path> LinkedPaths;
    RemainPaths.reserve(Paths.size());
    LinkedPaths.reserve(MaxSize);

    //convert list to vector
    for(std::list<S_Path>::const_iterator it = Paths.begin(); it != Paths.end(); ++it)
    {
        RemainPaths.push_back(*it);
    }
    
    //sort the remain paths to find the minimal cost path
    std::sort(RemainPaths.begin(), RemainPaths.end(), 
              [](const S_Path& a, const S_Path& b) { return a.Cost < b.Cost; });

    //find valid paths to link from smallest cost path
    for(int i = 0; i<RemainPaths.size() && LinkedPaths.size() < MaxSize; i++)
    {
        LinkedPaths.push_back(RemainPaths[i]);
        if (IsPathMakeCircle(LinkedPaths)) //Is it make circle?
        {
            LinkedPaths.pop_back(); //then do not connect
        }
    }

    return LinkedPaths;
}

std::vector<S_Path> InhuGraph::kruskal_with_union() const
{
    if (Paths.size() <= 1)
    {
        std::cout<<"There's no paths to connect"<<std::endl;
    }

    std::vector<S_Path> PathArr;
    PathArr.reserve(Paths.size());

    std::vector<int> UnionMap(Elements.size(), -1);

    //convert list to vector
    for(std::list<S_Path>::const_iterator it = Paths.begin(); it != Paths.end(); it++)
    {
        PathArr.push_back(*it);
    }

    //sort by cost
    std::sort(PathArr[0], PathArr[PathArr.size() - 1], [](const S_Path& a, const S_Path& b){return a.Cost < b.Cost;});
    
    //init
    

    for(int i = 0; i<PathArr.size(); i++)
    {
        int index1 = PathArr[i].Index1;
        int index2 = PathArr[i].Index2;
    }
}