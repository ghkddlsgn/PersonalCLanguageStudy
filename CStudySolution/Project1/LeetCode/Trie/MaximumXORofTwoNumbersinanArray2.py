from typing import Optional

class TrieNode():
    def __init__(self, ch, bit_idx) -> None:
        self.bit:str = ch
        self.bit_idx:int = bit_idx
        self.original_decimal_num = -1
        self.next:list[Optional[TrieNode]] = [None, None]


class Solution:
    def __init__(self) -> None:
        self.root = TrieNode('', -1)

    def findMaximumXOR(self, nums: list[int]) -> int:
        #init
        max_val = 0
        max_xor_num1 = -1
        max_xor_num2 = -1

        for xor_num1 in nums:
            self.add_num(xor_num1)
            xor_num2_str:str = ""
            cur_node = self.root
            for bit in self.bit32_padding(xor_num1): #greedy search to find max xor val
                inverse_bit = 0 if bit=='1' else 1
                cur_node = cur_node.next[inverse_bit] if cur_node.next[inverse_bit] else cur_node.next[int(bit)]
                xor_num2_str = xor_num2_str + cur_node.bit
            else:
                xor_num2:int = int(xor_num2_str, 2)
                xor_val = xor_num1 ^ xor_num2
                if xor_val > max_val: #if we found new max xor value, update
                    max_val = xor_val
                    max_xor_num1 = xor_num1
                    max_xor_num2 = xor_num2
                    print(f"found new max xor, max_val:{max_val}, num1:{max_xor_num1}, num2:{max_xor_num2}")
        return max_val
        
    def add_num(self, num:int):    
        bitstr = self.bit32_padding(num)
        #add num
        cur_node = self.root
        for idx, ch in enumerate(bitstr):
            if not cur_node.next[int(ch)]: #if node is not exist, create new one
                new_node = TrieNode(ch, idx)
                cur_node.next[int(ch)] = new_node
            cur_node = cur_node.next[int(ch)]
        else:
            #store original number at the leaf node for debug purpose
            cur_node.original_decimal_num = num
    
    def bit32_padding(self, num:int) -> str:
        #data preprocessing
        bitstr = bin(num)[2:]
        if len(bitstr) < 32:
            head = '0' * (32 - len(bitstr))
            bitstr = head + bitstr
        return bitstr
    
if __name__ == "__main__":
    nums = [3, 10, 5, 25, 2, 8]
    sol = Solution()
    result = sol.findMaximumXOR(nums)
    print(f"Maximum XOR is {result}")