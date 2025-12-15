#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TrieNode{
    char ch = '\0';
    int value = 0;
    std::vector<TrieNode*> next;

    TrieNode(char ch){
        this->ch = ch;
        next.resize(26);
    }
};

class MapSum {

    private:
    TrieNode root = TrieNode('\0');
    std::vector<TrieNode*> TrieNodes;
    
    public:
        MapSum() {
        }
        ~MapSum() {
            for(TrieNode* node:TrieNodes){
                delete node;
            }
        }
        
        void insert(string key, int val) {
            TrieNode* current_node = &root;
            int new_idx;
            for(char ch:key){
                new_idx = get_idx_from_ch(ch);
                if (!current_node->next[new_idx]){ //we don't have node for current ch?
                    TrieNode* new_node = new TrieNode(ch);
                    TrieNodes.push_back(new_node);
                    current_node->next[new_idx] = new_node; //prepare for next step
                    current_node = new_node;
                }
                else{
                    current_node = current_node->next[new_idx]; //if we node for current ch already exist, then go to next node
                }
            }
            current_node->value = val;
        }
        
        int sum(string prefix) {
            TrieNode* current_node = &root;
            int new_idx;
            int sum = 0;
            
            //first, going down to prefix
            for(char ch:prefix){
                new_idx = get_idx_from_ch(ch);
                if (!current_node->next[new_idx]){ //we don't have node for current ch?
                    std::cout<<"error, wrong prefix"<<std::endl;
                    return sum;
                }
                
                current_node = current_node->next[new_idx];
            }

            sum += get_tree_sum(*current_node);

            return sum;
        }

        int get_tree_sum(TrieNode& Target){
            int sum = Target.value;
            for(TrieNode* child:Target.next){
                if(!child) continue;

                sum += get_tree_sum(*child);
            }
            return sum;
        }

        int get_idx_from_ch(char ch){
            return ch - 97;
        }
    };
    
    /**
     * Your MapSum object will be instantiated and called as such:
     * MapSum* obj = new MapSum();
     * obj->insert(key,val);
     * int param_2 = obj->sum(prefix);
     */