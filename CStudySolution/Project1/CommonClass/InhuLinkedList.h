#pragma once
#include <iostream>

class InhuLinkedList;

struct LinkedList
{
    int Value = -1;
    LinkedList * NextLink = nullptr;
};
class InhuLinkedList
{
private:
    LinkedList Dummy;
    LinkedList * head = &Dummy;
    int size = 0;
public:
    InhuLinkedList(int a)
    {
        AddNewLink(a);
    }
    template<typename... Args>
    InhuLinkedList(int a, Args... args)
    {
        AddNewLink(a);
        AddNewLink(args...);
    }
    InhuLinkedList(){}
    ~InhuLinkedList()
    {
        LinkedList* cur = head->NextLink;

        while (cur!=nullptr)
        {
            LinkedList* Next = cur->NextLink;
            delete cur;
            cur = Next;
        }
    }
    
    void AddNewLink(int Input_Value) //Add new link on head
    {
        LinkedList * NewList = new LinkedList; //add new list
        NewList->Value = Input_Value;
        NewList->NextLink = head->NextLink;
        
        head->NextLink = NewList; //update dummy
        size++;
    }

    template<typename... Args>
    void AddNewLink(int a, Args... args)
    {
        AddNewLink(a);
        AddNewLink(args...);
    }
    
    void RemoveTargetValue(int Value)
    {
        LinkedList * cur = head->NextLink;
        LinkedList * PastList = head;
        
        while(1)
        {
            if(cur==nullptr) //search fail
            {
                std::cout<<"There's no Linked list match with Value : "<<Value<<std::endl;
                break;
            }
            if (cur->Value==Value) //Search Success, begin remove
            {
                PastList->NextLink = cur->NextLink;
                delete cur;
                size--;
                break;
            }
            PastList = cur;
            cur = cur->NextLink;
        }        
    }
    void PrintList() const
    {
        if (size == 0)
        {
            std::cout<<"There's nothing to print on Linked List"<<std::endl;
            return;
        }
        LinkedList* cur = head->NextLink;
        while(cur != nullptr)
        {
            std::cout<<cur->Value<<" ";
            cur = cur->NextLink;
        }
        std::cout<<std::endl;
    }

    bool GetData()
    {
        
    }
    void Insert(int Input_Value);
    void Init(LinkedList ref);
    int SetSortRule(LinkedList ref1, LinkedList ref2);
};