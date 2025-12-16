#pragma once
#include <array>
#include <ostream>
#include <vector>
#include <iostream>

struct TrieNode{
    int bit_pos = -1; //debug purpose
    int stored_num = -1;
    int stored_bit = -1;
    int child_vlevel_count = 0; //this can be used for naive maximum
    bool is_End = false;
    std::array<TrieNode*, 2> next_node{};
    
    TrieNode(int val, int exist_child_level, int level = -1):stored_bit(val),child_vlevel_count(exist_child_level), bit_pos(level){    }
};

class Solution {

    TrieNode root = TrieNode(-1,-1);
    std::vector<TrieNode*> nodes;
    public:

        Solution(){}
        ~Solution(){
            for(TrieNode* node:nodes){
                delete node;
            }
        }
        int findMaximumXOR(std::vector<int>& nums) {
            int global_max = 0;
            int global_max_number = nums[0];

            //add nodes first
            for(int i=0; i<nums.size(); i++){
                int target = nums[i];
                this->add_new_node(target);
                
                for(TrieNode* node:root.next_node){
                    get_max_xor(target, node, global_max, global_max_number);
                }
            }
            // std::cout<<"max xor value = "<<global_max<<", number is "<<global_max_number<<std::endl;
            return global_max;
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
                    if (cur_node->child_vlevel_count < cur_remain_child_num){
                        cur_node->child_vlevel_count = cur_remain_child_num;
                    }
                    cur_node = cur_node->next_node[cur_bit_value];
                }
                else { //need to create new node?
                    TrieNode * new_node = new TrieNode(cur_bit_value, cur_remain_child_num,cur_node->bit_pos + 1);
                    nodes.push_back(new_node);
                    cur_node->next_node[cur_bit_value] = new_node;
                    cur_node = new_node;
                }
                cur_remain_child_num--;
            }
            
            //add number at last node and mark as end
            cur_node->stored_num = input;
            cur_node->is_End = true;
        }

        void get_max_xor(int cur_num, TrieNode* cur_node, int&global_max, int&global_max_num, int cur_bit_pos_idx = 0, int local_max = 0){
            if (!cur_node) return;
            
            if(cur_node->is_End) std::cout<<std::endl;
            int target_bit = cur_num;
            target_bit = cur_num >> (cur_bit_pos_idx);
            target_bit = cur_num %2; //extract target bit only (0,1)

            if(cur_node->stored_bit != target_bit){
                local_max = local_max + (1 << cur_bit_pos_idx);
            }

            if(local_max>global_max){ //do we need to update maximum info?
                global_max = local_max;
                if(cur_node->is_End == true) global_max_num = cur_node->stored_num;
                // auto int_to_bin = [](int x) {
                //     if(x == 0) return std::string("0");
                //     std::string res;
                //     while(x) { res = char('0' + (x%2)) + res; x >>= 1; }
                //     return res;
                // };
                // std::cout << "max xor value = " << global_max 
                //           << ", number is " << cur_num << " (" << int_to_bin(cur_num) << ")"
                //           << " xor " << global_max_num << " (" << int_to_bin(global_max_num) << ")"
                //           << std::endl;
            }
            
            bool has_childs = false;
            for(TrieNode* node:cur_node->next_node){
                if(!node) continue;
                has_childs = true;
                int remain_bit_num = std::max(get_msb_level(cur_num) - cur_bit_pos_idx - 1, node->child_vlevel_count + 1);
                int bit_head_mask = (1 << (remain_bit_num)) - 1; //first, create 1111... bit
                bit_head_mask = bit_head_mask << (cur_node->bit_pos + 1); //then attach tail bit to ...0000 part
                int naive_max = local_max + bit_head_mask;
                if(naive_max<= global_max) continue;

                get_max_xor(cur_num, node, global_max, global_max_num, cur_bit_pos_idx + 1, local_max);
            }

            if(!has_childs){ //is it leaf node?
                int remain_bit = cur_num >> cur_bit_pos_idx;
                remain_bit = remain_bit << cur_bit_pos_idx;
                remain_bit = (remain_bit ^ 0) & (1 << (cur_bit_pos_idx - 1));
                local_max = local_max + remain_bit;
                if (local_max > global_max){
                    global_max = local_max;
                    global_max_num = cur_node->stored_num;
                }
            }
        }
};