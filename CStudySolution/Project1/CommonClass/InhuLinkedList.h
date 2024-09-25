#pragma once
#include <iostream>
#include <limits>
#include <vector>

class InhuLinkedList;

struct Node
{
    int Value = -1;
    Node * NextNode = nullptr;
public:
    Node(){}
    Node(int i):Value(i){}
};
class InhuLinkedList
{
private:
    Node Dummy;
    Node * head= &Dummy;
    int size = 0;
protected:
    void CopyPrivateValues(const InhuLinkedList & ref)
    {
        Dummy = ref.Dummy;
        head = ref.head;
        size = ref.size;
    }
public:
    InhuLinkedList(int a)
    {
        AddNewNode(a);
    }
    template<typename... Args>
    InhuLinkedList(int a, Args... args)
    {
        AddNewNode(a);
        AddNewNode(args...);
    }
    InhuLinkedList(){}
    ~InhuLinkedList()
    {
        DeleteAllNodes();
    }
    Node* GetHead() const {return head;}
    Node* GetFirstNode() const {return head->NextNode;}

    void DeleteAllNodes() //delete all nodes except dummy node.
    {
        Node* cur = head->NextNode;

        while (cur!=nullptr)
        {
            Node* Next = cur->NextNode;
            delete cur;
            cur = Next;
        }
    }
    InhuLinkedList& operator=(const InhuLinkedList& ref)
    {
        if (&ref == this) //self assignment?
        {
            return *this;
        }
        
        DeleteAllNodes();
        
        for(int a : ref.GetValues())
        {
            AddNewNode(a);
        }
        return *this;
    }
    
    void AddNewNode(int Input_Value) //Add new link on head
    {
        Node * NewList = new Node; //add new list
        NewList->Value = Input_Value;
        NewList->NextNode = head->NextNode;
        
        head->NextNode = NewList; //update dummy
        size++;
    }
    
    template<typename... Args>
    void AddNewNode(int a, Args... args)
    {
        AddNewNode(a);
        AddNewNode(args...);
    }
    void RemoveTargetValue(int Value)
    {
        Node * cur = head->NextNode;
        Node * PastList = head;
        
        while(1)
        {
            if(cur==nullptr) //search fail
            {
                std::cout<<"There's no Linked list match with Value : "<<Value<<std::endl;
                break;
            }
            if (cur->Value==Value) //Search Success, begin remove
            {
                PastList->NextNode = cur->NextNode;
                delete cur;
                size--;
                break;
            }
            PastList = cur;
            cur = cur->NextNode;
        }        
    }
    void PrintList() const
    {
        if (size == 0)
        {
            std::cout<<"There's nothing to print on Linked List"<<std::endl;
            return;
        }
        Node* cur = head->NextNode;
        while(cur != nullptr)
        {
            std::cout<<cur->Value<<" ";
            cur = cur->NextNode;
        }
        std::cout<<std::endl;
    }
    int TotalSum() const
    {
        Node * Cur = head;
        int Sum = 0;
        do{
            Cur = Cur->NextNode;
            Sum += Cur->Value;
        } while(Cur->NextNode);
        return Sum;
    }
    int Max() const
    {
        Node * cur = head->NextNode;
        int max = std::numeric_limits<int>::min();
        while(cur)
        {
            if (max<cur->Value)
            {
                max = cur->Value;
            }
            cur = cur->NextNode;
        }
        return max;
    }
    int Min() const
    {
        Node * cur = head->NextNode;
        int min = std::numeric_limits<int>::max();
        while(cur)
        {
            if (min>cur->Value)
            {
                min = cur->Value;
            }
            cur = cur->NextNode;
        }
        return min;
    }
    Node* Get(int TargetValue) const
    {
        Node * cur = head->NextNode;
        while(cur)
        {
            if (cur->Value == TargetValue) //found the value
            {
                return cur;
            }
            cur = cur->NextNode;
        }
        return nullptr;
    }
    Node* Get_Improved(int TargetValue) const //when found the target node, move it to the top of the link
    {
        Node * cur = head->NextNode;
        Node * past = head;
        
        while(cur)
        {
            if (cur->Value == TargetValue) //found the value
            {
                if (cur == head->NextNode)
                {
                    return cur; //found on 1st node
                }
                else 
                {
                    past->NextNode = cur->NextNode; 
                    cur->NextNode = head->NextNode;
                    head->NextNode = cur;
                    return cur; //found on elsewhere
                }
            }
            past = cur;
            cur = cur->NextNode;
        }
        return nullptr;
    }
    void Insert(int Index, int NodeValue) //Index start from 0(empty)
    {
        if (Index>size) //check index is invalid
        {
            std::cout<<"Tried to insert node on invalid Index : "<<Index<<std::endl;
        }
        Node * cur = head->NextNode;
        Node * NewNode = new Node(NodeValue);
        
        if (Index == 0) //case 1, index is 0
        {
            NewNode->NextNode = head->NextNode;
            head->NextNode = NewNode;
        }
        else
        {
            for(int i = 1; i<Index; i++) //case 2, handle rest of indices
            {
                cur = cur->NextNode;
            }
            NewNode->NextNode = cur->NextNode;
            cur->NextNode = NewNode;
        }
        size++;
    }
    int Delete(int TargetIndex) //Target Index starts from 0 (first element)
    {
        if (TargetIndex > size-1) //Check Target index is invalid
        {
            std::cout<<"Treid to search non-exist Index : "<<TargetIndex<<std::endl;
            return std::_Min_limit<int>();
        }

        Node * cur = head->NextNode;
        Node * past = head;
        int DeletedNodeValue = 0;
        if (TargetIndex == 0) //Case 1 : delete first node
        {
            head->NextNode = cur->NextNode;
            DeletedNodeValue = cur->Value;
            delete cur;
        }
        else //Case 2 : delete node that not first node.
        {
            for (int i = 1; i<TargetIndex; i++) //Get Target node
            {
                past = cur;
                cur = cur->NextNode;
            }
            past->NextNode = cur->NextNode;
            DeletedNodeValue = cur->Value;
            delete cur;
        }
        size--;
        return DeletedNodeValue;
    }
    bool IsSorted() const //Didn't check whether it's properly working or not
    {
        Node * cur = head->NextNode;
        int PastValue = std::numeric_limits<int>::min();
        while(cur)
        {
            if (PastValue<=cur->Value)
            {
                PastValue = cur->Value;
                cur = cur->NextNode;
            }
            else
            {
                return false;
            }
        }
        return true; //if everything is alright until the end, then return true
    }
    void DeleteDuplicatedItems()
    {
        Node * cur = head->NextNode;
        int PastValue;

        while (cur)
        {
            
        }
    }
    void ReverseElements()
    {
        Node * cur = head->NextNode;
        Node * past = nullptr;
        Node * next;

        //step 1 : inverse the elements
        while(cur)
        {
            //inverse the link
            next = cur->NextNode;
            cur->NextNode = past;

            //move to next node
            past = cur;
            cur = next;
        }

        //step 2 : set dummy direct at the end of elements
        head->NextNode = past;
    }
    std::vector<int> GetValues() const
    {
        Node * cur = GetFirstNode();
        std::vector<int> AllValues;
        while(cur)
        {
            AllValues.push_back(cur->Value);
            cur = cur->NextNode;
        }
        return AllValues;
    }
    bool IsLooping() const
    {
        return true;
    }
    void Concatenate(InhuLinkedList & ref) //this function will make other linked list as same as this class
    {
        //Find last node;
        Node * This_LastNode = GetFirstNode();
        while(This_LastNode)
        {
            This_LastNode = This_LastNode->NextNode;
        }

        if (This_LastNode == nullptr) // Is this list empty?
        {
            CopyPrivateValues(ref);
        }
        else
        {
            This_LastNode->NextNode = ref.GetFirstNode();
            ref.CopyPrivateValues(*this);
        }
    }
    void MergeSortedLinkedList(InhuLinkedList & ref)
    {
        Node * i = this->GetFirstNode();
        Node * j = ref.GetFirstNode();
        Node * cur = head;
        
        if(!!(this->IsSorted()&&ref.IsSorted())) //check everything is sorted
        {
            std::cout<<"Linked Lists are not sorted"<<std::endl;
            return;
        }

        //update cur
        while(i && j)
        {
            if (i->Value<=j->Value)
            {
                //add i to new list
                cur->NextNode = i;
                cur = i;
                i = cur->NextNode;
            }
            else
            {
                //add j to new list
                cur->NextNode = j;
                cur = j;
                j = cur->NextNode;
            }
        }

        if (i != nullptr) //concatenate remain nodes
        {
            cur->NextNode = i;
        }
        else
        {
            cur->NextNode = j;
        }

        //update private values for both lists
        size += ref.size;
        ref.CopyPrivateValues(*this);
    }
};