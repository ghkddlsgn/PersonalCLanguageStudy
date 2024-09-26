#pragma once
#include <iostream>

#include "LinkNode.h"

class InhuCircularList
{
private:
    Node Dummy;
    Node * head = nullptr;
    int size = 0;
protected:
    void Init()
    {
        Dummy.NextNode = &Dummy;
    }
    void DeleteAllNodes()
    {
        Node * cur = Dummy.NextNode;
        Node * next = Dummy.NextNode;
        while(cur)
        {
            next = cur->NextNode;
            delete cur;
            cur = next;
        }
        size = 0;
    }
public:
    InhuCircularList()
    {
        Init();
    }
    InhuCircularList(int a)
    {
        Init();
        AddNewNodeAtTheEnd(a);
    }
    template <typename... Args>
    InhuCircularList(int a, Args... args)
    {
        AddNewNodeAtTheEnd(a);
        (AddNewNodeAtTheEnd(args), ...);
    }

    ~InhuCircularList()
    {
        DeleteAllNodes();
    }
    
    void AddNewNodeAtTheEnd(int Value)
    {
        Node * NewNode = new Node;
        NewNode->Value = Value;
        
        if (head == nullptr) //is list empty?
        {
            Dummy.NextNode = NewNode;
            head = NewNode;
            NewNode->NextNode = head;
        }
        else //is list not empty?
        {
            GetTailNode()->NextNode = NewNode;
            NewNode->NextNode = head;
        }
        
        size++;
    }
    Node * GetTailNode() const
    {
        if (head==nullptr)
        {
            return nullptr;
        }
        
        Node* cur = head;
        while(cur->NextNode != head)
        {
            cur = cur->NextNode;
        }
        return cur;
    }
    void PrintList() const
    {
        if (head == nullptr)
        {
            std::cout<<"List is empty"<<std::endl;
            return;
        }

        Node * cur = Dummy.NextNode;
        
        std::cout<<"List : ";
        do
        {
        std::cout<<cur->Value<<" ";
        cur = cur->NextNode;
        } while(cur != head);

        std::cout<<std::endl;
    }
    void Insert(int NewValue,int index) //index starts from 0 (ahead of head node)
    {
        if (index>size)
        {
            std::cout<<"Input index larger then current size"<<std::endl;
            return;
        }
        Node * cur = &Dummy;
        if (index == 0)
        {
            Node * NewNode = new Node; //generate new node
            NewNode->Value = NewValue;
            size++;
            
            if (!head) //if list empty, just add new node on the list
            {
                head = NewNode;
                NewNode->NextNode = NewNode;
                Dummy.NextNode = NewNode;
            }
            else //if not empty, set NewNode as new head
            {
                NewNode->NextNode = head;
                Dummy.NextNode = NewNode;
                GetTailNode()->NextNode = NewNode;
                
                head = NewNode; //set NewNode as new head
            }
            return;
        }
        
        for (int i = 0; i< index; i++) //Get index'th node
        {
            cur = cur->NextNode;
        }

        if (cur->NextNode == head) //is cur is last node?
        {
            AddNewNodeAtTheEnd(NewValue);
        }
        else
        {
            Node * NewNode = new Node; //generate new node
            NewNode->Value = NewValue;
            size++;
            
            NewNode->NextNode = cur->NextNode;
            cur->NextNode = NewNode;
        }
    }
};