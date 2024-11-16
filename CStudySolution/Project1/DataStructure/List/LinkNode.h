#pragma once

struct Node
{
    int Value = -1;
    Node * NextNode = nullptr;
public:
    Node(){}
    Node(int i):Value(i){}
};