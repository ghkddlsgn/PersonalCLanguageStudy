#include <vector>

struct TreeN_Node;
class InhuBTree {
private:

    TreeN_Node* RootNode = nullptr;
    int node_size = 0; //single node value length
    int size = 0; //total node count
protected:
    TreeN_Node* CreateNewNode(int size = -1);
    void DeleteAllNodesFromBelow(TreeN_Node* node);
    void InsertNewValueOnRemainSpace(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode_1 = nullptr, TreeN_Node* NewChildNode_2 = nullptr);
    void DeleteValueFromNode(TreeN_Node* node, int DeleteIndex);
    void GetNewValueAddedResultOnNode(const TreeN_Node* node, int NewValue, std::vector<int>& ReturnValue, std::vector<TreeN_Node*>& ReturnNodeArr, TreeN_Node* NewChildNode = nullptr) const;
    void SplitNode(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode = nullptr);
    void MergeNode(TreeN_Node* node1, TreeN_Node* node2);
    void BorrowValueFromSibling();
    int GetInsertOrDeleteTargetIndex(const TreeN_Node* node, int TargetValue) const;
public:

    template <typename... Args>

    InhuBTree(int NodeSize,Args... Nodes)
    {
        node_size = NodeSize;
        (AddNewValue(Nodes), ...);
    }
    ~InhuBTree()
    {
        DeleteAllNodesFromBelow(RootNode);
    }
    TreeN_Node* SearchNode(int TargetValue) const;
    void AddNewValue(int NewValue);
    void DeleteNode(int TargetValue);
    void PrintTree() const;
};
