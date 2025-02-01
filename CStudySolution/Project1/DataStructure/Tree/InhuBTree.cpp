#pragma once
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

/*
if NewChildNode is nullptr, it means i split leaf node
if NewChildNode is not nullptr, it means i split internal node.
i need to put NewChildNode after Insert point
*/
void InhuBTree::SplitNode(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode)
{
    //check node is full
    if (node->len != node_size)
    {
        std::cout << "Node is not full" << std::endl;
        return;
    }

    int i = 0;

    //prepare parent node
    TreeN_Node* parentNode = node->ParentNode;
    if (parentNode == nullptr)
    {
        parentNode = CreateNewNode();
        parentNode->ChildNodeArr[0] = node;
        node->ParentNode = parentNode;
    }
    //create new nodes for split
    TreeN_Node* newNode = CreateNewNode();
    newNode->ParentNode = parentNode;


    int insert_index = GetInsertTargetIndex(NewValue, node);

    //create whole node values and child nodes
    int new_whole_node_values[node_size + 1];
    TreeN_Node* new_whole_node_child_nodes[node_size + 2];

    for (i = 0; i <insert_index - 1; i++)
    {
        new_whole_node_values[i] = node->Value[i];
        new_whole_node_child_nodes[i] = node->ChildNodeArr[i];
    }
    new_whole_node_child_nodes[insert_index] = node->ChildNodeArr[insert_index];
    new_whole_node_values[insert_index] = NewValue;
    new_whole_node_child_nodes[insert_index + 1] = NewChildNode; //this could be nullptr

    for (i = insert_index + 1; i < node_size + 1; i++)
    {
        new_whole_node_values[i] = node->Value[i];
        new_whole_node_child_nodes[i+1] = node->ChildNodeArr[i];
    }

    //initiate split node
    int split_index = (node_size/2) - 1;
    
    for (i = 0; i < split_index; i++)
    {
        node->Value[i] = new_whole_node_values[i];
        node->ChildNodeArr[i] = new_whole_node_child_nodes[i];
    }
    for (i = split_index; i < node_size; i++)
    {
        node->Value[i] = NULLVALUE;
        
    }

    //add 1 value to parent node

    int j = 0;
    for (i = split_index + 1; i < node_size + 1; i++)
    {
        newNode->Value[j] = new_whole_node_values[i];
        newNode->ChildNodeArr[j] = new_whole_node_child_nodes[i];
        j++;
    }
}

int InhuBTree::GetInsertTargetIndex(int TargetValue, TreeN_Node* node) const
{
    int len = node->len;
    
    int insert_index =  len-1/2;
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
    
    if (min_index != max_index) //logic error check
    {
        std::cout << "GetInsertTargetIndex error : min_index != max_index" << std::endl;
        return -1;
    }

    /*from now, min_index == max_index, so i need to figure out 
    whether insert before or after insert_index*/
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