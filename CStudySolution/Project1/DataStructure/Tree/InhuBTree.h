struct TreeN_Node {
    int* Value;
    TreeN_Node** ChildNode;
    int Height = 0;
    int len = 0;
    TreeN_Node* LNode = nullptr;
    TreeN_Node* RNode = nullptr;
    TreeN_Node(int NodeSize)
    {
        Value = new int[NodeSize];
        ChildNode = new TreeN_Node*[NodeSize + 1];
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
    void NodeSort(TreeN_Node* node);
public:
    template <typename... Args>
    InhuBTree(Args... Nodes)
    {
        (AddNewValue(Nodes), ...);
    }
    ~InhuBTree()
    {
        DeleteAllNodesFromBelow(RootNode);
    }
    bool SearchNode(int TargetValue, TreeN_Node *& LastSearchedNode);
    bool AddNewValue(int NewValue);
    bool DeleteNode(int TargetValue);
    void PrintTree();
};
