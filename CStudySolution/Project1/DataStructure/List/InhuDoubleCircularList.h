#pragma once
#include <limits>
#include <iostream>


typedef int NodeValue;

struct DoubleNode
{
	DoubleNode * PastNode = nullptr;
	DoubleNode * NextNode = nullptr;
	NodeValue Value;
};

class InhuDoubleCircularList
{
private:
	NodeValue value;
	DoubleNode Dummy;
	DoubleNode * head;
	int size;

protected:
	void Init()
	{
		Dummy.NextNode = Dummy;
		Dummy.Value = std::min<NodeValue>();
	}
	void DeleteAllNodes()
	{
		if (IsEmpty())
		{
			return;
		}

		DoubleNode * cur = head;
		head->PastNode->NextNode = nullptr; //leave a null as a mark on last node;
		while (cur->NextNode != nullptr) //delete every node except last node
		{
			cur = cur->NextNode;
			delete cur->PastNode;
		}
		delete cur; //delete last node
		size = 0;
	}
	bool IndexOverflowCheeck(int Index) const //return false if there's an error
	{
		if (index > size) //overflow?
		{
			std::cout << "Index overflow, current size of DoubleList : " << size << std::endl;
			return false;
		}
		if (index < 0)
		{
			std::cout << "Input nagative Index" << std::endl;
			return false;
		}
		
		return true;
	}
public:
	InhuDoubleCircularList()
	{
		Init();
	}
	template <typename... Args>
	InhuDoubleCircularList(NodeValue a, Args... args)
	{
		Init();
		(AddNewNodeAtTheEnd(args...),...);
		
	}
	~InhuDoubleCircularList()
	{
		DeleteAllNodes();
	}

	void AddNewNodeAtTheEnd(NodeValue NewNodeValue)
	{
		DoubleNode * NewNode = new DoubleNode;
		NewNode->Value = NewNodeValue;

		if (IsEmpty()) //if list is empty, set new head
		{
			Dummy.NextNode = NewNode;

			head = NewNode;
			NewNode->NextNode = NewNode;
			NewNode->PastNode = NewNode;
		}
		else
		{
			DoubleNode * LastNode = GetLastNode();
			LastNode->NextNode = NewNode;
			NewNode->PastNode = LastNode;
			NewNode->NextNode = head;
		}

		size++;
	}
	void InsertNewNodeAtTheIndex(NodeValue NewNodeValue, int Index)//Index starts from 0, 0 means it will become a new head
	{
		DoubleNode * NewNode = New DoubleNode;
		NewNode->Value = NewNodeValue;
		DoubleNode * InsertTargetNode = GetNodeFromIndex(Index);
		
		NewNode->NextNode = InsertTargetNode;
		NewNode->PastNode = InsertTargetNode->PastNode;

		InsertTargetNode->PastNode = NewNode;
		NewNode->PastNode->NextNode = NewNode;

		if (index == 0) //if index is 0, Update head
		{
			head = NewNode;
			Dummy.NextNode = head;
		}

		size++;
	}

	bool IsEmpty() const {return head ? true : false;}

	DoubleNode* GetNodeFromIndex(int Index) const //Index starts from 0
	{
		if (!IndexOverflowCheeck(Index))
		{
			return nullptr;
		}
		
		DoubleNode * cur = head;
		for (int i = 0; i < Index - 1; i++)
		{
			cur = cur->NextNode;
		}
		return cur;
	}
	DoubleNode* GetLastNode() const
	{
		if (IsEmpty())
		{
			std::cout<<"List is Empty"<<std::endl;
			return nullptr;
		}
		return head->PastNode;
	}
	void Delete(int Index) //Index starts from 0
	{
		if (!IndexOverflowCheeck())
		{
			return;
		}
		
		DoubleNode * cur = GetNodeFromIndex(Index);
		cur->PastNode->NextNode = cur->NextNode;
		cur->NextNode->PastNode = cur->PastNode;

		delete cur;
		if (Index == 0) // if it delete head, update new head
		{
			Dummy.NextNode = head->NextNode;
			head = head->NextNode
		}
		
		size--;
	}

	void PrintAllList() const
	{
		if (IsEmpty())
		{
			std::cout<<"List is empty"<<std::endl;
		}

		std::cout<<"List elements ";

		DoubleNode * cur = head;
		do
		{
			std::cout<<cur->Value<<" ";
			cur = cur->NextNode;
		}
		while(cur->NextNode != head)
	}
};