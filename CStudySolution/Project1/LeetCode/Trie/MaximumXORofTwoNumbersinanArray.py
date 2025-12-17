from calendar import c
from typing import Optional

class TrieNode:
    def __init__(self, bit:str = '', bit_pos_idx:int = -1) -> None:
        self.child_node:dict[str,TrieNode] = {}
        self.bit:str = bit
        self.bit_pos_idx = bit_pos_idx
        self.longest_bitnum_from_here = -1
        self.stored_decimal_num:int = -1
        self.is_end:bool = False

class Solution:
    def __init__(self) -> None:
        self.root:TrieNode = TrieNode()
        self.max_val = -1
        self.max_val_num1 = -1
        self.max_val_num2 = -1

    
    def findMaximumXOR(self, nums: list[int]) -> int:
        #init
        self.max_val = 0
        self.max_val_num2 = nums[0]

        self.add_new_TrieNode(nums[0])
        for i in range(1, len(nums)):
            self.add_new_TrieNode(nums[i])
            self.findMaxXor_recur(nums[i])
        
        return self.max_val
        
    def findMaxXor_recur(self, num, cur_bit_idx = -1, local_max=0, cur_node: Optional[TrieNode] = None):
        if cur_node == None:
            cur_node = self.root
            for key, next_node in cur_node.child_node.items():
                self.findMaxXor_recur(num, 0, cur_node=next_node)
            return
        
        #branch and bound
        naive_max = self.get_naive_max(cur_node, cur_bit_idx, local_max)
        if naive_max < self.max_val: return

        #update max from current node
        bit_str = bin(num)[2:]
        cur_bit_str = bit_str[cur_bit_idx]
        if cur_bit_str != cur_node.bit:
            local_max += (1<<cur_bit_idx)
        
        if local_max > self.max_val:
            self.update_max_val(local_max, num, cur_node.stored_decimal_num)

        #prepare for next node
        
        #edgecase handling
        if cur_bit_idx+1 == len(bit_str): #edgecase : is this the last bit?
            for child_node in cur_node.child_node.values(): #but there's more bit on trie?
                self.edge_case_input_bit_exhausted(num, local_max, child_node)
            return
        
        if len(cur_node.child_node) == 0: #thre's no child node remain? 
            if cur_bit_idx+1 < len(bit_str): #but i still have bits to conpare?
                self.edge_case_input_bit_remain(num, cur_node.stored_decimal_num, cur_bit_idx, local_max)
        
        for child in cur_node.child_node.values():
            self.findMaxXor_recur(num, cur_bit_idx + 1, local_max, child)
    
    def edge_case_input_bit_remain(self, num:int, num2:int, cur_bit_idx:int, local_max:int):
        local_max = 0
        bit_str = bin(num)
        cur_bit_idx += 1
        for bit_idx in range(cur_bit_idx, len(bit_str)):
            if bit_str[bit_idx] == '1':
                local_max += (1 << len(bit_str) - bit_idx - 1)
        
        if local_max > self.max_val:
            self.update_max_val(local_max, num, num2)
        
    
    def edge_case_input_bit_exhausted(self, num:int, local_max:int, cur_node:TrieNode): #if i checked all bits, but longer nums are remain in trie            
        if cur_node.bit == '1':
            local_max += 1
        
        if local_max > self.max_val:
            self.update_max_val(local_max, num, cur_node.stored_decimal_num)
        
        for child_node in cur_node.child_node.values():
            self.edge_case_input_bit_exhausted(num, local_max, child_node)

    def get_naive_max(self, cur_node:TrieNode, cur_bit_idx:int, local_max:int):
        naive_max = (1 << (cur_node.longest_bitnum_from_here + 1)) -1
        naive_max = naive_max << cur_bit_idx
        naive_max += local_max
        return naive_max

    def add_new_TrieNode(self, num:int):
        bin_str:str = bin(num)[2:]
        cur_node:TrieNode = self.root
        for idx, bin_ch in enumerate(bin_str):
            #find next cur_node
            if bin_ch not in cur_node.child_node: #need to create new node, then create
                new_node = TrieNode(bin_ch, idx)
                cur_node.child_node[bin_ch] = new_node
            cur_node = cur_node.child_node[bin_ch]

            if cur_node.longest_bitnum_from_here > len(bin_str[idx:]): #update longest bit num
                cur_node.longest_bitnum_from_here = len(bin_str[idx:])
        else:
            cur_node.is_end = True
            cur_node.stored_decimal_num = num
    
    def update_max_val(self, max_val:int, max_val_num1:int, max_val_num2:int):
        self.max_val = max_val
        self.max_val_num1 = max_val_num1
        self.max_val_num2 = max_val_num2
        print(f"new max_val: {self.max_val}, max_val_num1: {self.max_val_num1}, max_val_num2: {self.max_val_num2}")

if __name__ == "__main__":
    s = Solution()
    # nums = [3, 10, 5, 25, 2, 8]
    nums = [5,25]
    print("Maximum XOR is:", s.findMaximumXOR(nums))