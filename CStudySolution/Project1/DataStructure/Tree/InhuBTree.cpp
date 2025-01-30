#include <iostream>
#include "InhuBTree.h"
#include "Project1/SortAlgorithm.h"

void InhuBTree::DeleteAllNodesFromBelow(TreeN_Node* node)
{
    if (node == nullptr) return;
    for (int i = 0; i < node->len; i++)
    {
        DeleteAllNodesFromBelow(node->ChildNode[i]);
    }
    delete node;
    size--;
}

void InhuBTree::SplitNode(TreeN_Node* node, int NewValue)
{
    TreeN_Node* NewNode = new TreeN_Node(node_size);
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
                if (LastSearchedNode->ChildNode[i] == nullptr) 
                {
                    return false;
                }
                //if there's child node, go to the child node
                LastSearchedNode = LastSearchedNode->ChildNode[i];
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
            if (LastSearchedNode->ChildNode[node_len] == nullptr)
            {
                return false;
            }
            //if there's child node, go to the last child node
            LastSearchedNode = LastSearchedNode->ChildNode[node_len];
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
        
    }
    else
    {
        //add new value to target node's empty slot
        TargetNode->Value[TargetNode->len] = NewValue;
        TargetNode->len++;
        SelectSort(TargetNode->Value, TargetNode->len, true); //function from SortAlgorithm.h
        return true;
    }
}

bool InhuBTree::DeleteNode(int TargetValue)
{
}

void InhuBTree::PrintTree() const
{
}