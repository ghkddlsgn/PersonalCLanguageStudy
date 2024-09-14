#pragma once
#include <iostream>

class InhuLinkedList;

struct LinkedList
{
    int Value;
    LinkedList * NextLink;
};
class InhuLinkedList
{
private:
    LinkedList * head = nullptr;
    LinkedList * tail = nullptr;
    int size = 0;
public:
    InhuLinkedList(LinkedList* NewHead, LinkedList* NewTail, int length) :head(NewHead), tail(NewTail), size(length)
    {
        
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
    
    void AddNewLink(int Input_Value)
    {
        LinkedList * NewList = new LinkedList; //Make new linked list
        NewList->Value = Input_Value;
        NewList->NextLink = nullptr;

        if (head == nullptr) //Is this the first element?
        {
            head = NewList;
            tail = NewList;
        }
        else
        {
            tail->NextLink = NewList; //update tail
            tail = NewList;    
        }

        size++;
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
            if (head==tail)tail = nullptr;
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
};
