#include <iostream>
#include "InhuBTree.h"
#include "Project1/SortAlgorithm.h"

TreeN_Node* InhuBTree::CreateNewNode()
{
    TreeN_Node* newNode = new TreeN_Node(node_size);
    NodeArr[size] = newNode;
    size++;
    return newNode;
}

void InhuBTree::DeleteAllNodesFromBelow(TreeN_Node* node)
{
    if (node == nullptr) return;
    for (int i = 0; i < node->len; i++)
    {
        DeleteAllNodesFromBelow(node->ChildNodeArr[i]);
    }
    delete node;
    size--;
}

//this function should be excuted if node is not full
void InhuBTree::InsertNewValueOnRemainSpace(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode)
{
    //node is full?
    if (node->len == node_size)
    {
        std::cout << "InsertNewValueOnNode error : node is full, no space to insert" << std::endl;
        return;
    }

    int insert_index = GetInsertTargetIndex(node, NewValue);
    for (int i = node->len; i > insert_index; i--)
    {
        node->Value[i] = node->Value[i-1];
        node->ChildNodeArr[i+1] = node->ChildNodeArr[i];
    }
    node->Value[insert_index] = NewValue;
    node->ChildNodeArr[insert_index+1] = NewChildNode; //this can be nullptr
    node->len++;
}

void InhuBTree::GetNewValueAddedResultOnNode(const TreeN_Node* node, int NewValue, int*& ReturnValue, TreeN_Node**& ReturnNodeArr, TreeN_Node* NewChildNode) const

{
    int insert_index = GetInsertTargetIndex(node, NewValue);
    
    delete ReturnValue;
    delete ReturnNodeArr;

    ReturnValue = new int[node->len + 1];
    ReturnNodeArr = new TreeN_Node*[node->len + 2];

    //fill the left part
    for (int i = 0; i < insert_index; i++)
    {
        ReturnValue[i] = node->Value[i];
        ReturnNodeArr[i] = node->ChildNodeArr[i];
    }
    //fill the right part
    for (int i = insert_index + 1; i < node->len + 1; i++)
    {
        ReturnValue[i] = node->Value[i];
        ReturnNodeArr[i+1] = node->ChildNodeArr[i];
    }
    //fill the insert part
    ReturnValue[insert_index] = NewValue;
    ReturnNodeArr[insert_index+1] = NewChildNode; //this can be nullptr
}

/*
if NewChildNode is nullptr, it means i split leaf node
if NewChildNode is not nullptr, it means i split internal node.
i need to put NewChildNode after Insert point
*/
void InhuBTree::SplitNode(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode)
{
    if (node->len!=node_size)
    {
        std::cout << "SplitNode error : node is not full" << std::endl;
        return;
    }

    //prepare new node and parent node
    TreeN_Node* NewNode = CreateNewNode();
    NewNode->ParentNode = node->ParentNode;

    TreeN_Node* ParentNode = node->ParentNode;
    if (ParentNode == nullptr)
    {
        ParentNode = CreateNewNode();
        node->ParentNode = ParentNode;
        NewNode->ParentNode = ParentNode;
    }

    //get combined(node + new value, new child node) value and node array
    int insert_index = GetInsertTargetIndex(node, NewValue);

    int* WholeValue;
    TreeN_Node** WholeChildNodeArr;
    GetNewValueAddedResultOnNode(node, NewValue, WholeValue, WholeChildNodeArr, NewChildNode);
    
    //split node
    int split_index = (node_size-1)/2;

    //process the the split node itself : add to parent
    if (ParentNode->len != node_size) //ParentNode is not full?
    {
        InsertNewValueOnRemainSpace(ParentNode, WholeValue[split_index], NewNode);
    }
    else //ParentNode is full
    {
        SplitNode(ParentNode, WholeValue[split_index], NewNode);
    }

    //process the left node (original) : clear values
    for (int i = split_index + 1; i < node->len; i++)
    {
        node->Value[i] = NULLVALUE;
        node->ChildNodeArr[i + 1] = nullptr;
    }
    node->len = split_index;

    //process the right node (new one) : fill values
    int j = 0;
    for (int i = split_index + 1; i < node->len + 1; i++)
    {
        NewNode->Value[j] = WholeValue[i];
        NewNode->ChildNodeArr[j] = WholeChildNodeArr[i + 1];
        j++;
    }
    NewNode->ChildNodeArr[j+1] = WholeChildNodeArr[node->len + 1]; //add the last ptr
    NewNode->len = j;

    delete[] WholeValue;
    delete[] WholeChildNodeArr;
}


int InhuBTree::GetInsertTargetIndex(const TreeN_Node* node, int TargetValue) const
{
    int len = node->len;
    
    int insert_index = (len-1)/2;
    int min_index = 0;
    int max_index = len-1;


    while(min_index <= max_index)
    {
        if (TargetValue == node->Value[insert_index])
        {
            return insert_index;
        }
        else if (TargetValue < node->Value[insert_index])
        {
            max_index = insert_index - 1;
        }   
        else if (TargetValue > node->Value[insert_index])
        {
            min_index = insert_index + 1;
        }
        insert_index = (min_index + max_index) / 2;
    }

    /*from now, min_index == max_index, so i need to figure out 
    whether insert before or after insert_index
    !!return index could be out of bound!!
    */
    if (TargetValue < node->Value[insert_index])
    {
        return insert_index; //insert before
    }
    else
    {
        return insert_index + 1; //insert after
    }
}

//it return last searched node, so if i want to add new node, i can add at last searched node
bool InhuBTree::SearchNode(int TargetValue, TreeN_Node *& LastSearchedNode) const
{
    if (!RootNode)
    {
        std::cout << "Tree is empty" << std::endl;
        return false;
    }
    
    LastSearchedNode = RootNode;
    int node_len = 0;
    int i = 0;

    while(1)
    {
        node_len = LastSearchedNode->len;
        for (i = 0; i < node_len; i++)
        {
            if (TargetValue < LastSearchedNode->Value[i])
            {
                //if there's no child node, i need to add new value on this node (LastSearchedNode)
                if (LastSearchedNode->ChildNodeArr[i] == nullptr) 
                {
                    return false;
                }
                //if there's child node, go to the child node
                LastSearchedNode = LastSearchedNode->ChildNodeArr[i];
                break;
            }
            if (LastSearchedNode->Value[i] == TargetValue)
            {
                return true;
            }
        }
        //if value is bigger than all value in node, check the last child node
        if (i == node_len)
        {
            //if there's no child node, i need to add new value on this node (LastSearchedNode)
            if (LastSearchedNode->ChildNodeArr[node_len] == nullptr)
            {
                return false;
            }
            //if there's child node, go to the last child node
            LastSearchedNode = LastSearchedNode->ChildNodeArr[node_len];
        }
    }
}

//it always add new value on leaf node or split node 
bool InhuBTree::AddNewValue(int NewValue)
{
    TreeN_Node* TargetNode;
    if (SearchNode(NewValue, TargetNode))
    {
        std::cout << "Value already exists" << std::endl;
        return false;
    }

    //Target node is full?
    if (TargetNode->len == node_size)
    {
        //start split node
        SplitNode(TargetNode, NewValue);

    }
    else
    {
        //add new value to target node's empty slot -> this will always happen on leaf node
        TargetNode->Value[TargetNode->len] = NewValue;
        TargetNode->len++;
        SelectSort(TargetNode->Value, TargetNode->len, true);
    }
}

bool InhuBTree::DeleteNode(int TargetValue)
{
}

void InhuBTree::PrintTree() const
{
}