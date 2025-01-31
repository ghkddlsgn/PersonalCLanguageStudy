#include <iostream>
#include "InhuBTree.h"

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

void InhuBTree::SortNodeValue(TreeN_Node* node)
{
    
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
        
        //sort value
        int temp[TargetNode->len + 1];
        for (int i = 0; i < TargetNode->len; i++)
        {
            temp[i] = TargetNode->Value[i];
        }
        //add new value to temp array
        temp[TargetNode->len] = NewValue;
        //sort temp array
        SortNodeValue(TargetNode);

    }
    else
    {
        //add new value to target node's empty slot
        TargetNode->Value[TargetNode->len] = NewValue;
        TargetNode->len++;
        SortNodeValue(TargetNode);
        return true;
    }
}

bool InhuBTree::DeleteNode(int TargetValue)
{
}

void InhuBTree::PrintTree() const
{
}