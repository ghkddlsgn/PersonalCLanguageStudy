#pragma once
#include <iostream>

class InhuLinkedList;

struct LinkedList
{
    int Value;
    LinkedList * NextLink = nullptr;
};
class InhuLinkedList
{
private:
    LinkedList * head = nullptr;
    int size = 0;
public:
    void AddNewLink(int Input_Value) //Add new link on head
    {
        LinkedList * NewList = new LinkedList;
        NewList->Value = Input_Value;

        if (head != nullptr)
        {
            NewList->NextLink = head;
        }
        head = NewList;
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
        if (head == nullptr)
        {
            std::cout<<"Remove fail, List is empty"<<std::endl;
        }
        LinkedList* cur = head;

        //step 1 : check 1st list
        if (head->Value == Value)
        {
            LinkedList * NewHead = head->NextLink;
            delete head;
            head = NewHead;
            size--;
            return;
        }
        else if (head->NextLink == nullptr)
        {
            std::cout<<"Search Fail, Target Value : "<<Value<<std::endl;
            return;
        }
        
        //step 2 : check whole list
        LinkedList * PastList = head;
        cur = head->NextLink;
        
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
        LinkedList* cur = head;
        while(cur != nullptr)
        {
            std::cout<<cur->Value<<" ";
            cur = cur->NextLink;
        }
        std::cout<<std::endl;
    }
    
    void Insert(int Input_Value);
    void Init(LinkedList ref);
    int SetSortRule(LinkedList ref1, LinkedList ref2);

public: //constructor and destructor
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
        LinkedList* cur = head;

        while (cur!=nullptr)
        {
            LinkedList* Next = cur->NextLink;
            delete cur;
            cur = Next;
        }
    }
};