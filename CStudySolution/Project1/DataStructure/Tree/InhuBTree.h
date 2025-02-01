#define NULLVALUE -9999999
struct TreeN_Node {
    int* Value;
    TreeN_Node** ChildNodeArr = nullptr;
    TreeN_Node* ParentNode = nullptr;
    int Height = 0;
    int len = 0; //current node value count
    TreeN_Node(int NodeSize)
    {
        Value = new int[NodeSize];
        ChildNodeArr = new TreeN_Node*[NodeSize + 1];
        for (int i = 0; i < NodeSize; i++) //init value as -9999999
        {
            Value[i] = NULLVALUE;
        }
    }
    ~TreeN_Node()
    {
        delete[] Value;
        delete[] ChildNodeArr;
    }
};

class InhuBTree {

private:
    TreeN_Node* RootNode = nullptr;
    TreeN_Node** NodeArr = nullptr;
    int node_size = 0; //single node value length
    int size = 0; //total node count
protected:
    TreeN_Node* CreateNewNode();
    void DeleteAllNodesFromBelow(TreeN_Node* node);
    void AddNewValueOnNode(TreeN_Node* node, int NewValue);
    void SplitNode(TreeN_Node* node, int NewValue, TreeN_Node* NewChildNode=nullptr);
    int GetInsertTargetIndex(int TargetValue, TreeN_Node* node) const;
public:
    template <typename... Args>

    InhuBTree(int NodeSize,Args... Nodes)
    {
        node_size = NodeSize;
        (AddNewValue(Nodes), ...);
    }
    ~InhuBTree()
    {
        /*
        i don't use DeleteAllNodesFromBelow.
        because i want to ensure all nodes are deleted
        even some nodes are not properly connected with each other
        */
        for (int i = 0; i < size; i++)
        {
            delete NodeArr[i];
        }
        delete[] NodeArr;
    }
    bool SearchNode(int TargetValue, TreeN_Node *& LastSearchedNode) const;
    bool AddNewValue(int NewValue);
    bool DeleteNode(int TargetValue);
    void PrintTree() const;
};
