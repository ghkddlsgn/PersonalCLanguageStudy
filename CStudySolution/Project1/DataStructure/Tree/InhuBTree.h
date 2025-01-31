struct TreeN_Node {
    int* Value;
    TreeN_Node** ChildNodeArr;
    TreeN_Node* ParentNode;
    int Height = 0;
    int len = 0;
    TreeN_Node(int NodeSize)
    {
        Value = new int[NodeSize];
        ChildNodeArr = new TreeN_Node*[NodeSize + 1];
    }
    ~TreeN_Node()
    {
        delete[] Value;
        delete[] ChildNodeArr;
    }
};

class InhuBTree {
    TreeN_Node* RootNode = nullptr;
    int node_size = 0; //single node value length
    int size = 0; //total node count
protected:
    void DeleteAllNodesFromBelow(TreeN_Node* node);
    void SplitNode(TreeN_Node* node, int NewValue);
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
    bool SearchNode(int TargetValue, TreeN_Node *& LastSearchedNode) const;
    bool AddNewValue(int NewValue);
    bool DeleteNode(int TargetValue);
    void PrintTree() const;
};
