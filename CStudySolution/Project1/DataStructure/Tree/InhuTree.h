#pragma once
#include <iostream>

struct TreeNode
{
    int Value;
    TreeNode* LNode = nullptr;
    TreeNode* RNode = nullptr;
};

class InhuTree
{
private:
    TreeNode * root = nullptr;
    int size = 0;
protected:
    int GetMaxTreeNodeNum(int MaxLevel) const // return 2^(n-1)
    {
        int result = 1;
        for (int i = 0; i<MaxLevel-1; i++)
        {
            result = result * 2;
        }
        return result;
    }
    void DeleteAllNodesFromBelow(TreeNode * node)
    {
        if (node == nullptr) return;
        
        DeleteAllNodesFromBelow(node->LNode);
        DeleteAllNodesFromBelow(node->RNode);
        delete node;
    }
public:
    
    template <typename... Args>
    InhuTree(Args... Nodes)
    {
        (Insert(Nodes), ...);
    }
    ~InhuTree()
    {
        DeleteAllNodesFromBelow(root);
    }

    static void print_Preorder(const TreeNode * Node)
    {
        if (Node == nullptr) return;
        std::cout<<Node->Value<<" ";
        print_Preorder(Node->LNode);
        print_Preorder(Node->RNode);
    }
    static void print_Inorder(const TreeNode * Node)
    {
        if (Node == nullptr) return;
        print_Inorder(Node->LNode);
        std::cout<<Node->Value<<" ";
        print_Inorder(Node->RNode);
    }
    void Insert(int NewValue)
    {
        TreeNode * NewNode = new TreeNode;
        NewNode->Value = NewValue;

        if (root == nullptr)
        {
            root = NewNode;
            size++;
            return;
        }

        TreeNode * Target = root;
        TreeNode * Parent = nullptr;
        
        while(Target != nullptr)
        {
            Parent = Target;
            if (NewValue < Target->Value)
            {
                Target = Target->LNode;
            }
            else if (NewValue > Target->Value)
            {
                Target = Target->RNode;
            }
            else
            {
                std::cout<<"Value already exist"<<std::endl;
                delete NewNode;
                return;
            }
        }
        //found the empty position
        if (NewValue < Parent->Value)
        {
            Parent->LNode = NewNode;
        }
        else
        {
            Parent->RNode = NewNode;
        }
        size++;
    }
};