#pragma once
#include <iostream>
#include <vector>
#include <stack>

struct TreeN_Node {
    int* Value;
    int** ChildNode;
    int Height = 0;
    TreeN_Node* LNode = nullptr;
    TreeN_Node* RNode = nullptr;
    TreeN_Node(int NodeSize)
    {
        Value = new int[NodeSize];
        ChildNode = new int*[NodeSize + 1];
    }
    ~TreeN_Node()
    {
        delete[] Value;
        delete[] ChildNode;
    }
};

class InhuBTree {
    TreeN_Node* RootNode = nullptr;
    int node_size = 0;
    int size = 0;
protected:
    void DeleteAllNodesFromBelow(TreeN_Node* node);
public:
    template <typename... Args>
    InhuBTree(Args... Nodes)
    {
        (AddNewNode(Nodes), ...);
    }
    ~InhuBTree()
    {
        DeleteAllNodesFromBelow(RootNode);
    }
    void AddNewNode(int NewValue);
    void DeleteNode(int TargetValue);
    void SearchNode(int TargetValue);
    void PrintTree();
};
