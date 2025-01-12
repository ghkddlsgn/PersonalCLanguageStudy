#include "InhuTree.h"

// TreeNode implementations
TreeNode::TreeNode(int a) : Value(a) {}

TreeNode::TreeNode() : Value(0) {}

// InhuTree protected methods
int InhuTree::GetMaxTreeNodeNum(int MaxLevel) const {
    int result = 1;
    for (int i = 0; i < MaxLevel - 1; i++) {
        result = result * 2;
    }
    return result;
}

void InhuTree::DeleteAllNodesFromBelow(TreeNode* node) {
    if (node == nullptr) return;
    DeleteAllNodesFromBelow(node->LNode);
    DeleteAllNodesFromBelow(node->RNode);
    delete node;
}

// InhuTree public methods
void InhuTree::CreateTreeFromPreOrder(std::vector<int> Arr) {
    std::cout << "Execute CreateTreeFromPreOrder" << std::endl;
    
    //init
    DeleteAllNodesFromBelow(root);
    size = Arr.size();

    //variables
    std::stack<TreeNode*> P_Stack;
    TreeNode* PastNode;
    TreeNode* NewNode;
    TreeNode* TargetNode;

    //first
    root = new TreeNode(Arr[0]);
    PastNode = root;

    //Main loop
    for (int i = 1; i < Arr.size(); i++) {
        NewNode = new TreeNode(Arr[i]);
        while(1) {
            //L Node Handle
            if (NewNode->Value < PastNode->Value) {
                if(!PastNode->LNode) { //location empty?
                    PastNode->LNode = NewNode;
                    break;
                }
                P_Stack.push(PastNode);
                PastNode = PastNode->LNode;
                continue;
            }
            else { //R Node Handle
                if(P_Stack.top()->Value < NewNode->Value) {
                    TargetNode = P_Stack.top();
                    P_Stack.pop();
                    continue;
                }
                else {
                    if (!PastNode->RNode) {
                        PastNode->RNode = NewNode;
                        break;
                    }
                    PastNode = PastNode->RNode;
                    continue;
                }
            }
        }
    }
}

InhuTree::~InhuTree() {
    DeleteAllNodesFromBelow(root);
}

TreeNode* InhuTree::GetRoot() const {
    return root;
}

void InhuTree::print_Preorder(const TreeNode* Node) {
    if (Node == nullptr) return;
    std::cout << Node->Value << " ";
    print_Preorder(Node->LNode);
    print_Preorder(Node->RNode);
}

void InhuTree::print_Inorder(const TreeNode* Node) {
    if (Node == nullptr) return;
    print_Inorder(Node->LNode);
    std::cout << Node->Value << " ";
    print_Inorder(Node->RNode);
}

int InhuTree::count_node_below_node(TreeNode* Targetnode) const
{ 
    if (!Targetnode) return 0;
    return 1 + count_node_below_node(Targetnode->LNode) + count_node_below_node(Targetnode->RNode);
}

void InhuTree::AddNewNode(int NewValue) {
    TreeNode* NewNode = new TreeNode;
    NewNode->Value = NewValue;

    if (root == nullptr) {
        root = NewNode;
        size++;
        return;
    }

    TreeNode* Target = root;
    TreeNode* Parent = nullptr;
    
    while(Target != nullptr) {
        Parent = Target;
        if (NewValue < Target->Value) {
            Target = Target->LNode;
        }
        else if (NewValue > Target->Value) {
            Target = Target->RNode;
        }
        else {
            std::cout << "Value already exist" << std::endl;
            delete NewNode;
            return;
        }
    }
    
    if (NewValue < Parent->Value) {
        Parent->LNode = NewNode;
    }
    else {
        Parent->RNode = NewNode;
    }
    size++;
}

TreeNode* InhuTree::Search(int SearchValue, TreeNode*& ParentNode) const {
    TreeNode* TargetNode = root;
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return nullptr;
    }

    while(TargetNode) {
        if (TargetNode->Value == SearchValue) {
            return TargetNode;
        }
        if (TargetNode->Value < SearchValue) {
            ParentNode = TargetNode;
            TargetNode = TargetNode->LNode;
        }
        else {
            ParentNode = TargetNode;
            TargetNode = TargetNode->RNode;
        }
    }

    std::cout << "Target Node is not exist" << std::endl;
    return nullptr;
}

bool InhuTree::DeleteNode(int TargetValue, TreeNode* TargetNode = nullptr) {
    TreeNode* TargetParentNode;
    if (TargetNode == nullptr) {
        TargetNode = Search(TargetValue, TargetParentNode);
    }

    if(!TargetNode) {
        std::cout << "TargetNode is not exist" << std::endl;
        return false;
    }

    //if targetnode is leaf node, just delete it
    if (IsLeafNode(TargetNode)) {
        delete TargetNode;
        size--;
        return true;
    }

    TreeNode* ReplaceNode_Parent;
    TreeNode* ReplaceNode = GetClosestInorderNode(TargetNode, ReplaceNode_Parent);
    DetachAndInsertNode(TargetNode, TargetParentNode, ReplaceNode, ReplaceNode_Parent);

    delete TargetNode;
    size--;

    return true;
}

void InhuTree::DetachAndInsertNode(TreeNode* ToNode, TreeNode*& ToNode_Parent, TreeNode* FromNode, TreeNode*& FromNode_Parent)
{
    if (!FromNode) {
        return;
    }

    bool ToNode_isLeftChild = IsLeftChild(ToNode, ToNode_Parent);
    bool FromNode_isLeftChild = IsLeftChild(FromNode, FromNode_Parent);
    


    //Detach FromNode
    if (IsLeafNode(FromNode)) {
        if (FromNode_isLeftChild) {
            FromNode_Parent->LNode = nullptr;
        }
        else {
            FromNode_Parent->RNode = nullptr;
        }
    }
    else{
        TreeNode* ReplaceNode_Parent;
        TreeNode* ReplaceNode = GetClosestInorderNode(FromNode, ReplaceNode_Parent);
        DetachAndInsertNode(FromNode, FromNode_Parent, ReplaceNode, ReplaceNode_Parent);
    }
    
    //Attach FromNode to TargetNode's position
}

TreeNode* InhuTree::GetMaxNodeInTree(TreeNode* RootNode, TreeNode*& SearchedNode_Parent) const {
    if (RootNode == nullptr) {
        std::cout << "GetMaxNodeInTree : root is nullptr" << std::endl;
        return nullptr;
    }
    
    SearchedNode_Parent = nullptr;
    TreeNode* TargetNode = RootNode;
    while(TargetNode->RNode != nullptr) {
        SearchedNode_Parent = TargetNode;
        TargetNode = TargetNode->RNode;
    }

    return TargetNode;
}

TreeNode* InhuTree::GetMinNodeInTree(TreeNode* RootNode, TreeNode*& SearchedNode_Parent) const {
    if (RootNode == nullptr) {
        std::cout << "GetMinNodeInTree : root is nullptr" << std::endl;
        return nullptr;
    }

    SearchedNode_Parent = nullptr;
    TreeNode* TargetNode = RootNode;
    while(TargetNode->LNode != nullptr) {
        SearchedNode_Parent = TargetNode;
        TargetNode = TargetNode->LNode;
    }
    return TargetNode;
}

void InhuTree::PrintTreeNode(const TreeNode* node, int indent) const {
    if (node != nullptr) {
        if (node->RNode)
            PrintTreeNode(node->RNode, indent + 4);
        
        if (indent)
            std::cout << std::string(indent, ' ');
        
        std::cout << node->Value << std::endl;

        if (node->LNode)
            PrintTreeNode(node->LNode, indent + 4);
    }
}

TreeNode *InhuTree::GetClosestInorderNode(TreeNode *TargetNode, TreeNode *&ParentNode) const
{
    if (TargetNode == nullptr) {
        std::cout << "Target Node is not exist" << std::endl;
        return nullptr;
    }

    TreeNode * ReturnValue = GetInorderSuccessor(TargetNode, ParentNode);
    if (ReturnValue == nullptr) {
        ReturnValue = GetInorderPredecessor(TargetNode, ParentNode);
    }
    return ReturnValue;
}

TreeNode *InhuTree::GetInorderSuccessor(TreeNode *TargetNode, TreeNode *&SuccessorParentNode) const
{
    SuccessorParentNode = TargetNode;
    TreeNode* ReturnValue = TargetNode->RNode;

    if (ReturnValue == nullptr){
        std::cout << "Inorder Successor is not exist" << std::endl;
        return nullptr;
    }

    while(ReturnValue->LNode != nullptr)
    {
        SuccessorParentNode = ReturnValue;
        ReturnValue = ReturnValue->LNode;
    }
    return ReturnValue;
}

TreeNode *InhuTree::GetInorderPredecessor(TreeNode *TargetNode, TreeNode *&PredecessorParentNode) const
{
    PredecessorParentNode = TargetNode;
    TreeNode* ReturnValue = TargetNode->LNode;

    if (ReturnValue == nullptr){
        std::cout << "Inorder Predecessor is not exist" << std::endl;
        return nullptr;
    }

    while(ReturnValue->RNode != nullptr)
    {
        PredecessorParentNode = ReturnValue;
        ReturnValue = ReturnValue->RNode;
    }
    return ReturnValue;
}

int InhuTree::GetNodeBalance(TreeNode* TargetNode) {
    if (!TargetNode) {
        std::cout << "Target Node is not exist" << std::endl;
        return 0;
    }
    return 0; // Note: Implementation seems incomplete in original code
}

void InhuTree::LL_Rotation(TreeNode* L1_ParentNode, TreeNode* L1, TreeNode* L2) {
    L1->LNode = L2->RNode;
    L2->RNode = L1;

    if (L2->Value < L1_ParentNode->Value) {
        L1_ParentNode->LNode = L2;
    }
    else {
        L1_ParentNode->RNode = L2;
    }
    root = L2;
}

void InhuTree::RR_Rotation(TreeNode* R1_ParentNode, TreeNode* R1, TreeNode* R2) {
    R1->RNode = R2->LNode;
    R2->LNode = R1;

    if (R1_ParentNode->Value < R2->Value) {
        R1_ParentNode->RNode = R2;
    }
    else {
        R1_ParentNode->LNode = R2;   
    }
}

void InhuTree::LR_Rotation(TreeNode* R1_ParentNode, TreeNode* a, TreeNode* b, TreeNode* c) {
    RR_Rotation(a, b, c);
    LL_Rotation(a, c, b);
}

void InhuTree::RL_Rotation(TreeNode* R1_ParentNode, TreeNode* a, TreeNode* b, TreeNode* c) {
    LL_Rotation(a, c, b);
    RR_Rotation(a, b, c);
}
