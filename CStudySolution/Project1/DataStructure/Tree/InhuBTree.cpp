#include <iostream>
//#include <algorithm>
#include "InhuBTree.h"
#include <algorithm>

#define NULLVALUE 9999999

struct TreeN_Node {
    std::vector<int> Value;
    std::vector<TreeN_Node*> ChildNodeArr;
    TreeN_Node* ParentNode = nullptr;
    int Height = 0;
    int len = 0; //current node value count
    TreeN_Node(int NodeSize)
    {
        Value.resize(NodeSize, NULLVALUE);
        ChildNodeArr.resize(NodeSize + 1, nullptr);
    }
};

TreeN_Node* InhuBTree::CreateNewNode()
{
    TreeN_Node* newNode = new TreeN_Node(node_size);
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

void InhuBTree::DeleteValueFromNode(TreeN_Node* node, int DeleteIndex)
{
    //step 1 : delete value on target node
    //drag values left 1
    for (int i = DeleteIndex; i < node->len - 1; i++)
    {
        node->Value[i] = node->Value[i+1];
    }
    //drag child nodes left 1
    TreeN_Node* temp = node->ChildNodeArr[DeleteIndex];
    for (int i = DeleteIndex; i < node->len; i++)
    {
        node->ChildNodeArr[i] = node->ChildNodeArr[i+1];
    }
    node->ChildNodeArr[node->len] = nullptr;
    node->Value[node->len-1] = NULLVALUE; //remove the last value
    node->len--;

    //merge child nodes
    MergeNode(temp, node->ChildNodeArr[DeleteIndex]);
}

void InhuBTree::InsertNewValueOnRemainSpace(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode_1, TreeN_Node* NewChildNode_2)
//this function should be excuted if node is not full
{
    //node is full?
    if (node->len == node_size)
    {
        std::cout << "InsertNewValueOnNode error : node is full, no space to insert" << std::endl;
        return;
    }

    int insert_index = GetInsertOrDeleteTargetIndex(node, NewValue);
    for (int i = node->len; i > insert_index; i--)
    {
        node->Value[i] = node->Value[i-1];
        node->ChildNodeArr[i+1] = node->ChildNodeArr[i];
    }
    node->Value[insert_index] = NewValue;
    node->ChildNodeArr[insert_index] = NewChildNode_1; //this can be nullptr
    node->ChildNodeArr[insert_index+1] = NewChildNode_2; //this can be nullptr
    node->len++;
}

void InhuBTree::GetNewValueAddedResultOnNode(const TreeN_Node* node, int NewValue, std::vector<int>& ReturnValue, std::vector<TreeN_Node*>& ReturnNodeArr, TreeN_Node* NewChildNode) const
{
    int insert_index = GetInsertOrDeleteTargetIndex(node, NewValue);
    
    ReturnValue.clear();
    ReturnNodeArr.clear();
    
    ReturnValue.reserve(node->len + 1);
    ReturnNodeArr.reserve(node->len + 2);
    
    //fill the left part
    for (int i = 0; i < insert_index; i++)
    {
        ReturnValue.push_back(node->Value[i]);
    }
    for (int j = 0; j <= insert_index; j++)
    {
        ReturnNodeArr.push_back(node->ChildNodeArr[j]);
    }

    //fill the insert part
    ReturnValue.push_back(NewValue);
    ReturnNodeArr.push_back(NewChildNode);

    //fill the right part
    for (int i = insert_index; i < node->len; i++)
    {
        ReturnValue.push_back(node->Value[i]);
    }
    for (int j = insert_index + 1; j < node->len + 1; j++)
    {
        ReturnNodeArr.push_back(node->ChildNodeArr[j]);
    }
}

//this function need to be fixed : NewValue -> NewIntArray
void InhuBTree::SplitNode(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode)
{
    /*
    if NewChildNode is nullptr, it means i split leaf node
    if NewChildNode is not nullptr, it means i split internal node.
    i need to put NewChildNode after Insert point
    */
    if (node->len!=node_size) //check node is full
    {
        std::cout << "SplitNode error : node is not full" << std::endl;
        return;
    }

    //prepare new node and parent node
    TreeN_Node* NewNode = CreateNewNode();
    TreeN_Node* ParentNode = node->ParentNode;
    if (ParentNode == nullptr)
    {
        ParentNode = CreateNewNode();
        node->ParentNode = ParentNode;
        RootNode = ParentNode;
    }
    NewNode->ParentNode = ParentNode;

    //get combined(node + new value, new child node) value and node array
    int insert_index = GetInsertOrDeleteTargetIndex(node, NewValue);

    std::vector<int> WholeValue;
    std::vector<TreeN_Node*> WholeChildNodeArr;
    GetNewValueAddedResultOnNode(node, NewValue, WholeValue, WholeChildNodeArr, NewChildNode);
    
    //split node
    int split_index = (node_size-1)/2;

    //process the left node (original)
    for (int i = 0; i < split_index; i++) //fill values
    {
        node->Value[i] = WholeValue[i];
    }
    node->len = split_index;

    for (int i = split_index; i < node_size; i++) //clear values
    {
        node->Value[i] = NULLVALUE;
        node->ChildNodeArr[i + 1] = nullptr;
        if (node->ChildNodeArr[i] != nullptr)
        {
            node->ChildNodeArr[i]->ParentNode = node;
        }
    }

    //process the right node (new one) : fill values
    int j = 0;
    for (int i = split_index + 1; i < node_size + 1; i++)
    {
        NewNode->Value[j] = WholeValue[i];
        NewNode->ChildNodeArr[j] = WholeChildNodeArr[i];

        if (NewNode->ChildNodeArr[j] != nullptr)
        {
            NewNode->ChildNodeArr[j]->ParentNode = NewNode;
        }
        j++;
    }
    NewNode->len = j;

    NewNode->ChildNodeArr[j] = WholeChildNodeArr[WholeChildNodeArr.size() - 1]; //add the last ptr
    if (NewNode->ChildNodeArr[j] != nullptr)
    {
        NewNode->ChildNodeArr[j]->ParentNode = NewNode;
    }

    //process the the split node itself : promote to parent
    if (ParentNode->len != node_size) //ParentNode is not full?
    {
        //parent node's child arr also setted in this code
        InsertNewValueOnRemainSpace(ParentNode, WholeValue[split_index], node, NewNode);
    }
    else //ParentNode is full
    {
        SplitNode(ParentNode, WholeValue[split_index], NewNode);
    }
}

void InhuBTree::MergeNode(TreeN_Node* node1, TreeN_Node* node2)
{
    if (!node1 && !node2) //there's no node to merge?
    {
        return;
    }

    if (!node1 && node2)
    {

    }
    
    if (node1 && !node2)
    {

    }

    TreeN_Node* ParentNode = node1->ParentNode;
    
}

int InhuBTree::GetInsertOrDeleteTargetIndex(const TreeN_Node* node, int TargetValue) const
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
TreeN_Node* InhuBTree::SearchNode(int TargetValue) const
{
    if (!RootNode)
    {
        return nullptr;
    }

    TreeN_Node* LastSearchedNode = RootNode;

    int i = 0;
    while(1)
    {
        int node_len = LastSearchedNode->Value.size();
        if (node_len == 0) //handle empty node
        {
            return LastSearchedNode;
        }

        for (i = 0; i < node_len; i++)
        {
            if (TargetValue < LastSearchedNode->Value[i]) //find proper place
            {
                //if there's no child node, i need to add new value on this node (LastSearchedNode)
                if (LastSearchedNode->ChildNodeArr[i] == nullptr) 
                {
                    return LastSearchedNode;
                }
                //if there's child node, go to the child node
                LastSearchedNode = LastSearchedNode->ChildNodeArr[i];
                break;
            }
            else if (LastSearchedNode->Value[i] == TargetValue) //check if value is already in this node
            {
                return LastSearchedNode; //value is already in this node
            }
        }
        //if value is bigger than all value in node, check the last child node
        if (i >= node_len)
        {
            //if there's no child node, i need to add new value on this node (LastSearchedNode)
            if (LastSearchedNode->ChildNodeArr[i] == nullptr)

            {
                return LastSearchedNode;
            }
            //if there's child node, go to the last child node
            LastSearchedNode = LastSearchedNode->ChildNodeArr[i];
        }
    }
}

//it always add new value on leaf node or split node 
void InhuBTree::AddNewValue(int NewValue)
{
    TreeN_Node* TargetNode;
    if (RootNode == nullptr)
    {

        RootNode = CreateNewNode();
        TargetNode = RootNode;
    }
    else
    {
        TargetNode = SearchNode(NewValue);
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
        std::sort(TargetNode->Value.begin(), TargetNode->Value.begin() + TargetNode->len);
    }
}

void InhuBTree::DeleteNode(int DeleteValue)
{
    //case 1 : simply delete no child, there's other value in same node : just delete the value
    //case 2 : delete and merge no child, become empty node : begin merge -> Bring value from sibling or parent
    //case 3 : borrow
    
    if (RootNode == nullptr)
    {
        std::cout<<"DeleteNode error : Tree is empty"<<std::endl;
        return;
    }
    TreeN_Node* TargetNode = SearchNode(DeleteValue);
    int DeleteIndex = GetInsertOrDeleteTargetIndex(TargetNode, DeleteValue);

    DeleteValueFromNode(TargetNode, DeleteIndex);
}

void InhuBTree::PrintTree() const
{
    if (RootNode == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    std::vector<std::pair<TreeN_Node*, std::string>> queue;
    queue.push_back({RootNode, "0"});
    
    int level = 0;
    while (!queue.empty())
    {
        int levelSize = queue.size();
        
        std::cout << "Level " << level << ": ";
        
        for (int i = 0; i < levelSize; i++)
        {
            TreeN_Node* current = queue[i].first;
            std::string position = queue[i].second;
            
            // Print node values with position
            std::cout << position << ":[ ";
            for (int j = 0; j < current->len; j++)  // Changed from Value.size() to len
            {
                if (current->Value[j] != NULLVALUE)
                {
                    std::cout << current->Value[j] << " ";
                }
            }
            std::cout << "] ";
            
            // Add children to queue with their positions
            for (int j = 0; j <= current->len; j++)  // Changed from Value.size() to len
            {
                if (current->ChildNodeArr[j] != nullptr)
                {
                    std::string childPosition = position + "-" + std::to_string(j);
                    queue.push_back({current->ChildNodeArr[j], childPosition});
                }
            }
        }
        
        std::cout << std::endl;
        
        queue.erase(queue.begin(), queue.begin() + levelSize);
        level++;
    }
}