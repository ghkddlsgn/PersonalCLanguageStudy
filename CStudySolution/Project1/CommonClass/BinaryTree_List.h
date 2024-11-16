#pragma once

struct Binary_tree_Node
{
    int value;
    Binary_tree_Node * pre_node;
    Binary_tree_Node * next_node;
};
class BinaryTree_List
{
private:
    int node_count = 0;
    Binary_tree_Node * root;
    int current_max_height = 0;
public:
    
};
