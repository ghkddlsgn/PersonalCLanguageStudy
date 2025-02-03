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

void InhuTree::PrintTreeSideways(int indentSize) const
{
    if (!root) {
            std::cout << "(empty tree)" << std::endl;
            return;
        }
        PrintTreeSidewaysHelper(root, 0, indentSize);
}

void InhuTree::PrintTreeSidewaysHelper(const TreeNode* node, int level, int indent) const
{
    if (node == nullptr) {
        return;
    }

    // 1) Print the right child first (above the current node)
    PrintTreeSidewaysHelper(node->RNode, level + 1, indent);

    // 2) Print the current node, indented according to level
    // Each 'level' means we shift by (level * INDENT) spaces
    std::cout << std::string(level * indent, ' ') << node->Value << std::endl;

    // 3) Print the left child (below the current node)
    PrintTreeSidewaysHelper(node->LNode, level + 1, indent);
}

void InhuTree::print_Preorder(const TreeNode *Node)
{
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

int InhuTree::GetSubNodeLevel(TreeNode *TargetNode) const
{
    if (!TargetNode){
        return 0; //return -1 at the end, so init height can be 0
    }
    return 1 + std::max(GetSubNodeLevel(TargetNode->LNode), GetSubNodeLevel(TargetNode->RNode));
}

int InhuTree::GetNodeBalance(TreeNode *TargetNode) const
{
    if (!TargetNode)
    {
        std::cout<<"GetNodeBalanace : TargetNode is not exist"<<std::endl;
        return 0;
    }
    int Height_L = 0;
    int Height_R = 0;   
    if (TargetNode->LNode)
    {
        Height_L = GetSubNodeLevel(TargetNode->LNode);
    }
    if (TargetNode->RNode)
    {
        Height_R = GetSubNodeLevel(TargetNode->RNode);
    }
    
    return Height_L-Height_R;
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
        std::cout << "Search : Tree is empty" << std::endl;
        return nullptr;
    }

    while(TargetNode) {
        if (TargetNode->Value == SearchValue) {
            return TargetNode;
        }
        if (TargetNode->Value < SearchValue) {
            ParentNode = TargetNode;
            TargetNode = TargetNode->RNode;
        }
        else {
            ParentNode = TargetNode;
            TargetNode = TargetNode->LNode;
        }
    }

    std::cout << "Search : Target Node is not exist" << std::endl;
    return nullptr;
}

bool InhuTree::DeleteNode(int TargetValue, TreeNode* TargetNode) {
    TreeNode* TargetParentNode{};
    if (TargetNode == nullptr) {
        TargetNode = Search(TargetValue, TargetParentNode);
    }

    if(!TargetNode) {
        std::cout << "DeleteNode : TargetNode is not exist" << std::endl;
        return false;
    }

    //if targetnode is leaf node, just delete it
    if (IsLeafNode(TargetNode)) {
        if (IsLeftChild(TargetNode, TargetParentNode)) {
            TargetParentNode->LNode = nullptr;
        }
        else {
            TargetParentNode->RNode = nullptr;
        }
        delete TargetNode;
        size--;
        return true;
    }

    TreeNode* ReplaceNode_Parent;
    TreeNode* ReplaceNode = GetClosestInorderNode(TargetNode, ReplaceNode_Parent);
    DetachAndInsertNode(TargetNode, TargetParentNode);

    delete TargetNode;
    size--;

    return true;
}

void InhuTree::DetachAndInsertNode(TreeNode* TargetNode, TreeNode*& TargetNode_Parent)
{
    //if targetnode is leaf node, just delete it
    if (IsLeafNode(TargetNode)) {
        if (IsLeftChild(TargetNode, TargetNode_Parent)) {
            TargetNode_Parent->LNode = nullptr;
        }
        else {
            TargetNode_Parent->RNode = nullptr;
        }
        return;
    }

    //find replace node
    TreeNode* ReplaceNode_Parent;
    TreeNode* ReplaceNode = GetClosestInorderNode(TargetNode, ReplaceNode_Parent);
    //Detach TargetNode
    bool TargetNode_isLeftChild = IsLeftChild(TargetNode, TargetNode_Parent);

    DetachAndInsertNode(ReplaceNode, ReplaceNode_Parent);

    //Attach ReplaceNode to TargetNode's position
    if (TargetNode_isLeftChild) {
        TargetNode_Parent->LNode = ReplaceNode;
    }
    else {
        TargetNode_Parent->RNode = ReplaceNode;
    }

    ReplaceNode->LNode = TargetNode->LNode;
    ReplaceNode->RNode = TargetNode->RNode;
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

bool InhuTree::IsLeafNode(TreeNode *TargetNode) const
{
    if (TargetNode->LNode == nullptr && TargetNode->RNode == nullptr) {
        return true;
    }
    return false;
}

bool InhuTree::IsLeftChild(TreeNode *TargetNode, TreeNode *ParentNode) const
{
    if (ParentNode->LNode == TargetNode) {
        return true;
    }
    return false;
}

TreeNode* InhuTree::LL_Rotation(TreeNode* L1_ParentNode, TreeNode* L1) {
    //check valid
    if (L1 == nullptr) {
        std::cout << "LL_Rotation : L1 is nullptr" << std::endl;
        return nullptr;
    }
    if (!L1->LNode) {
        std::cout << "LL_Rotation : not valid" << std::endl;
        return nullptr;
    }
    TreeNode* L2 = L1->LNode;

    //rearrange subtree related with l1,l2
    L1->LNode = L2->RNode;
    L2->RNode = L1;
    
    //rearrange higher tree
    if (L1 == root){
        root = L2;
        return L2;
    }

    bool isleft = IsLeftChild(L1, L1_ParentNode);
    if (isleft) {
        L1_ParentNode->LNode = L2;
    }
    else {
        L1_ParentNode->RNode = L2;
    }
    return L2;
}

TreeNode* InhuTree::RR_Rotation(TreeNode* R1_ParentNode, TreeNode* R1) {
    //check valid
    if (R1 == nullptr) {
        std::cout << "RR_Rotation : R1 is nullptr" << std::endl;
        return nullptr;
    }
    if (!R1->RNode) {
        std::cout << "RR_Rotation : not valid" << std::endl;
        return nullptr;
    }
    TreeNode* R2 = R1->RNode;
    
    //rearrange subtree related with R1,R2
    R1->RNode = R2->LNode;
    R2->LNode = R1;
    
    //rearrange higher tree
    if (R1 == root){
        root = R2;
        return R2;
    }

    bool isleft = IsLeftChild(R1, R1_ParentNode);
    if (isleft) {
        R1_ParentNode->LNode = R2;
    }
    else {
        R1_ParentNode->RNode = R2;
    }
    return R2;
}

TreeNode* InhuTree::LR_Rotation(TreeNode* a_ParentNode, TreeNode* a) {
    if (!(a->LNode && a->LNode->RNode)) {
        std::cout << "LR_Rotation : node is not exist" << std::endl;
        return nullptr;
    }
    TreeNode* b = a->LNode;
    RR_Rotation(a,b);
    return LL_Rotation(a_ParentNode,a);
}

TreeNode* InhuTree::RL_Rotation(TreeNode* a_ParentNode, TreeNode* a) {
    if (!(a->RNode && a->RNode->LNode)) {
        std::cout << "RL_Rotation : node is not exist" << std::endl;
        return nullptr;
    }
    TreeNode* b = a->RNode;
    LL_Rotation(a,b);
    return RR_Rotation(a_ParentNode,a);
}

void InhuTree::BalanceTree(TreeNode *TargetNode, TreeNode* TargetNode_Parent)
{
    if (!TargetNode) {
        return;
    }
    TreeNode* TopNode = TargetNode;
    bool LSub_Sub_Node_Exist;
    bool RSubNode_Exist;
    int L_SubtreeHeight;
    int R_SubtreeHeight;
    //keep balance tree until balance value reaches -1, 0, 1
    while(abs(GetNodeBalance(TopNode)) >= 2) {
        //if this is true, that means we have at least 2 nodes in right or left subtree
        int Height_L = GetSubNodeLevel(TopNode->LNode);
        int Height_R = GetSubNodeLevel(TopNode->RNode);
        if (Height_L > Height_R) {
            LSub_Sub_Node_Exist = TopNode->LNode->LNode ? true : false;
            RSubNode_Exist = TopNode->LNode->RNode ? true : false;
            //both left and right node exist
            if (LSub_Sub_Node_Exist && RSubNode_Exist) {
                L_SubtreeHeight = GetSubNodeLevel(TopNode->LNode->LNode);
                R_SubtreeHeight = GetSubNodeLevel(TopNode->LNode->RNode);
                if (L_SubtreeHeight > R_SubtreeHeight) {
                    TopNode = LL_Rotation(TargetNode_Parent, TopNode);
                }
                else {
                    TopNode = LR_Rotation(TargetNode_Parent, TopNode);
                }
            }
            else if (!LSub_Sub_Node_Exist) {
                TopNode = LR_Rotation(TargetNode_Parent, TopNode);
            }
            else {
                TopNode = LL_Rotation(TargetNode_Parent, TopNode);
            }
        }
        else {
            RSubNode_Exist = TopNode->RNode->RNode ? true : false;
            LSub_Sub_Node_Exist = TopNode->RNode->LNode ? true : false;
            //both left and right node exist
            if (LSub_Sub_Node_Exist && RSubNode_Exist) {
                L_SubtreeHeight = GetSubNodeLevel(TopNode->RNode->LNode);
                R_SubtreeHeight = GetSubNodeLevel(TopNode->RNode->RNode);
                if (L_SubtreeHeight > R_SubtreeHeight) {
                    TopNode = RL_Rotation(TargetNode_Parent, TopNode);
                }
                else {
                    TopNode = RR_Rotation(TargetNode_Parent, TopNode);
                }
            }
            else if (!RSubNode_Exist) {
                TopNode = RL_Rotation(TargetNode_Parent, TopNode);
            }
            else {
                TopNode = RR_Rotation(TargetNode_Parent, TopNode);
            }
        }
        std::cout<<"modify_count : "<<modify_count++<<std::endl;
        PrintTreeSideways(4);
        std::cout<<std::endl;
    }

    //recursivly check every node in the tree
    BalanceTree(TopNode->LNode, TopNode);
    BalanceTree(TopNode->RNode, TopNode);

    return;
}
