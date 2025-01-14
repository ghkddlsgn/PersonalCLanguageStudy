﻿#pragma once
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int Value;
    int Height = 0;
    TreeNode* LNode = nullptr;
    TreeNode* RNode = nullptr;
    TreeNode(int a);
    TreeNode();
};

class InhuTree {
private:
    TreeNode* root = nullptr;
    int size = 0;

protected:
    int GetMaxTreeNodeNum(int MaxLevel) const;
    void DeleteAllNodesFromBelow(TreeNode* node);

public:
    void CreateTreeFromPreOrder(std::vector<int> Arr);
    
    template <typename... Args>
    InhuTree(Args... Nodes) {
        (AddNewNode(Nodes), ...);
    }
    ~InhuTree();

    TreeNode* GetRoot() const;
    static void print_Preorder(const TreeNode* Node);
    static void print_Inorder(const TreeNode* Node);
    int count_node_below_node(TreeNode* Targetnode) const;
    void PrintTreeNode(const TreeNode* node, int indent = 0) const;
    TreeNode* GetClosestInorderNode(TreeNode* TargetNode, TreeNode*& ParentNode) const;
    TreeNode* GetInorderSuccessor(TreeNode* TargetNode, TreeNode*& SuccessorParentNode) const;
    TreeNode* GetInorderPredecessor(TreeNode* TargetNode, TreeNode*& PredecessorParentNode) const;
    bool IsLeafNode(TreeNode* TargetNode) const;
    bool IsLeftChild(TreeNode* TargetNode, TreeNode* ParentNode) const;

    void AddNewNode(int NewValue);
    TreeNode* Search(int SearchValue, TreeNode*& ParentNode) const;
    bool DeleteNode(int TargetValue, TreeNode* TargetNode = nullptr);
    void DetachAndInsertNode(TreeNode* TargetNode, TreeNode*& TargetNode_Parent);
    TreeNode* GetMaxNodeInTree(TreeNode* RootNode, TreeNode*& SearchedNode_Parent) const;
    TreeNode* GetMinNodeInTree(TreeNode* RootNode, TreeNode*& SearchedNode_Parent) const;
    int GetNodeBalance(TreeNode* TargetNode);
    
    void LL_Rotation(TreeNode* L1_ParentNode, TreeNode* L1, TreeNode* L2);
    void RR_Rotation(TreeNode* R1_ParentNode, TreeNode* R1, TreeNode* R2);
    void LR_Rotation(TreeNode* R1_ParentNode, TreeNode* a, TreeNode* b, TreeNode* c);
    void RL_Rotation(TreeNode* R1_ParentNode, TreeNode* a, TreeNode* b, TreeNode* c);
};