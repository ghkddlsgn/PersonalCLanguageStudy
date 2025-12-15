#pragma once
#include <array>
#include <tuple>
#include <vector>
#include <iostream>

struct TrieNode{
    int level = -1; //debug purpose
    int val = -1;
    int exist_child_level = 0; //this can be used for naive maximum
    int decimal_num = -1;
    bool is_End = false;
    std::array<TrieNode*, 2> next_node{};
    
    TrieNode(int val, int exist_child_level, int level = -1):val(val),exist_child_level(exist_child_level), level(level){    }
};

class Solution {

    TrieNode root;
    public:
        int findMaximumXOR(std::vector<int>& nums) {
            int maximum_amount = 0;

            for(int i=0; i<nums.size(); i++){
                this->add_new_node(nums[i]);
                
            }
        }

        int get_msb_level(int input) const{
            if (input <0){
                std::cout<<"input should be positive";
                return -1;
            }

            int max_bit_level = 0;
            while(input > 0){
                input = input >> 1;
                max_bit_level++;
            }
            
            return max_bit_level;
        }

        void add_new_node(int input){
            TrieNode* cur_node = &root;
            int max_bit_level = get_msb_level(input);

            int cur_remain_child_num = max_bit_level - 1;
            int cur_bit_value = -1;
            for(int i = 0; i<max_bit_level; i++){
                cur_bit_value = (input % 2 == 1) ? 1 : 0;
                if (cur_node->next_node[cur_bit_value]){ //node already exist?
                    if (cur_node->exist_child_level < cur_remain_child_num){
                        cur_node->exist_child_level = cur_remain_child_num;
                    }
                    cur_node = cur_node->next_node[cur_bit_value];
                }
                else { //need to create new node?
                    TrieNode * new_node = new TrieNode(cur_bit_value, cur_remain_child_num,cur_node->level + 1);
                    cur_node->next_node[cur_bit_value] = new_node;
                    cur_node = new_node;
                }
                cur_remain_child_num--;
            }
            
            //add number at last node and mark as end
            cur_node->decimal_num = input;
            cur_node->is_End = true;
        }
};