#pragma once
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int Value;
    int Height = 0;
    TreeNode* LNode = nullptr;
    TreeNode* RNode = nullptr;
    TreeNode(int a)
    {
        Value = a;
    }
    TreeNode()
    {
        int Value = 0;
        TreeNode* LNode = nullptr;
        TreeNode* RNode = nullptr;
    }
};

class InhuTree
{
private:
    TreeNode * root = nullptr;
    int size = 0;
protected:

    //ssibal
    void CreateTreeFromPreOrder(std::vector<int> Arr)
    {
        DeleteAllNodesFromBelow(root);
        TreeNode * NewNode = nullptr;
        TreeNode * CompareTarget = nullptr;
        std::stack<TreeNode*> PointerStack;
        
        if (1 <= Arr.size()) //Create Root
        {
            root = new TreeNode(Arr[0]);
            PointerStack.push(root);
            CompareTarget = root;
        }
        
        for (int i = 1; i<Arr.size(); i++)
        {
            NewNode = new TreeNode(Arr[i]);

            if (NewNode->Value < CompareTarget->Value) // Put New node on left side
            {
                CompareTarget->LNode = NewNode;
            }
            else if (NewNode->Value < PointerStack.top()->Value) // put new node on right side
            {
                PointerStack.top()->RNode = NewNode;
            }
            else
            {
                //pop stack until it 
                PointerStack.top()->RNode = NewNode;
            }

            PointerStack.push(CompareTarget);
            CompareTarget = NewNode;
            
        }
    }

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
        (AddNewNode(Nodes), ...);
    }
    ~InhuTree()
    {
        DeleteAllNodesFromBelow(root);
    }

    TreeNode * GetRoot() const {return root;}
    
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
    void AddNewNode(int NewValue)
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
    TreeNode* Search(int SearchValue, TreeNode* & ParentNode) const
    {
        TreeNode * TargetNode = root;
        if (root == nullptr) //Check empty
        {
            std::cout<<"Tree is empty"<<std::endl;
            return nullptr;
        }

        while(TargetNode) //Search
        {
            if (TargetNode->Value == SearchValue)
            {
                return TargetNode;
            }
            if (TargetNode->Value < SearchValue)
            {
                ParentNode = TargetNode;
                TargetNode = TargetNode->LNode;
            }
            else
            {
                ParentNode = TargetNode;
                TargetNode = TargetNode->RNode;
            }
        }

        //there's no target node in a tree
        std::cout<<"Target Node is not exist"<<std::endl;
        return nullptr;
    }
    bool DeleteNode(int TargetValue)
    {
        TreeNode * TargetParentNode;
        TreeNode * TargetNode = Search(TargetValue,TargetParentNode);
        TreeNode * ReplaceNode;
        TreeNode * ReplaceNode_Parent;

        if(!TargetNode)
        {
            std::cout<<"TargetNode is not exist"<<std::endl;
            return false;
        }

        //Choose the replace node
        ReplaceNode = GetMinNodeInTree(TargetNode, ReplaceNode_Parent);
        
        //Move to Replace node to Target Node's location
        // 1 : update Replace node's original Parent node pointer as null
        if (ReplaceNode)
        {
            ReplaceNode_Parent->LNode = nullptr;
        }
        // 2 : If there's a parent node, update the pointer as replace node
        if (TargetParentNode)
        {
            if (TargetParentNode->LNode == TargetNode)
            {
                TargetParentNode->LNode = ReplaceNode;
            }
            else
            {
                TargetParentNode->RNode = ReplaceNode;
            }
        }
        // 3 : update replaceNode
        ReplaceNode->RNode = TargetNode->RNode;
        ReplaceNode->LNode = TargetNode->LNode;
        
        //Delete TargetNode
        delete TargetNode;
        size--;

        return true;
    }
    TreeNode * GetMaxNodeInTree(TreeNode* RootNode, TreeNode* & SearchedNode_Parent) const
    {
        if (RootNode == nullptr)
        {
            std::cout<<"GetMaxNodeInTree : root is nullptr"<<std::endl;
            return nullptr;
        }
        
        SearchedNode_Parent = nullptr;
        TreeNode * TargetNode = RootNode;
        while(TargetNode->RNode != nullptr) //find rightest value
        {
            SearchedNode_Parent = TargetNode;
            TargetNode = TargetNode->RNode;
        }

        return TargetNode;
    }
    TreeNode * GetMinNodeInTree(TreeNode* RootNode, TreeNode* & SearchedNode_Parent) const
    {
        if (RootNode == nullptr)
        {
            std::cout<<"GetMinNodeInTree : root is nullptr"<<std::endl;
            return nullptr;
        }

        SearchedNode_Parent = nullptr;
        TreeNode * TargetNode = RootNode;
        while(TargetNode->LNode != nullptr) //find leftest value
        {
            SearchedNode_Parent = TargetNode;
            TargetNode = TargetNode->LNode;
        }
        return TargetNode;
    }

    void PrintTreeNode(const TreeNode * node, int indent = 0) const
    {
        if (node != nullptr)
        {
            if (node->RNode)  // Print right subtree first, so it appears on top
                PrintTreeNode(node->RNode, indent + 4);
            
            if (indent)
                std::cout << std::string(indent, ' ');
            
            std::cout << node->Value << std::endl;

            if (node->LNode)  // Then print left subtree
                PrintTreeNode(node->LNode, indent + 4);
        }
    }


    
    int GetNodeBalance(TreeNode * TargetNode)
    {
        if (!TargetNode)
        {
            std::cout<<"Target Node is not exist"<<std::endl;
            return 0;
        }
    }
    
    void LL_Rotation(TreeNode * L1_ParentNode, TreeNode * L1, TreeNode * L2)
    {
        L1->LNode = L2->RNode;
        L2->RNode = L1;

        if (L2->Value < L1_ParentNode->Value) //Update ParentNode's Pointer
        {
            L1_ParentNode->LNode = L2;
        }
        else
        {
            L1_ParentNode->RNode = L2;
        }
        root = L2;
    }
    void RR_Rotation(TreeNode * R1_ParentNode, TreeNode * R1, TreeNode * R2)
    {
        R1->RNode = R2->LNode;
        R2->LNode = R1;

        if (R1_ParentNode->Value < R2->Value) //Update ParentNode's Pointer
        {
            R1_ParentNode->RNode = R2;
        }
        else
        {
            R1_ParentNode->LNode = R2;   
        }
    }

    void LR_Rotation(TreeNode * R1_ParentNode, TreeNode * a, TreeNode * b, TreeNode * c)
    {
        RR_Rotation(a,b,c);
        LL_Rotation(a,c,b);
    }
    void RL_Rotation(TreeNode * R1_ParentNode, TreeNode * a, TreeNode * b, TreeNode * c)
    {
        LL_Rotation(a,c,b);
        RR_Rotation(a,b,c);
    }
};