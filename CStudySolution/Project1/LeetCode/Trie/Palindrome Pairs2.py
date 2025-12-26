class TrieNode:
    def __init__(self, r_ch, r_ch_idx) -> None:
        self.ch:str = r_ch
        self.ch_idx:int = r_ch_idx
        self.next:dict[str, TrieNode] = {}
        self.saved_s_word:str = ""
        self.saved_s_idx:int = -1
        self.pal_from_below:set[int] = set()

class Solution:
    def __init__(self) -> None:
        self.root:TrieNode = TrieNode("Root", -1)
        self.words:set[str] = set()


    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        result:list[list[int]] = []

        for i, word in enumerate(words): #add
            self.add_word(i, word)
        
        for i, word in enumerate(words): #compare
            result.extend(self.search_pal(i, word))
        
        return result

    def add_word(self, word_idx:int, word:str):
        #add reverse
        r_word = word[::-1]
        cur_node = self.root
        for i, reversed_ch in enumerate(r_word):
            if reversed_ch not in cur_node.next: #need to add new node?
                #create new node
                new_node = TrieNode(reversed_ch, i)
                cur_node.next[reversed_ch] = new_node
            #go to below
            cur_node = cur_node.next[reversed_ch]
            #update cur_node's info
            if self.check_boundary(i, r_word) and self.get_str_is_pal(r_word[i+1:]):
                cur_node.pal_from_below.add(word_idx)
        #at last, save s word at the end node
        else:
            cur_node.saved_s_word = word
            cur_node.saved_s_idx = word_idx
    
    def search_pal(self, s_word_idx:int, s_word:str) -> list[list[int]]:
        result:list[list[int]] = []
        cur_node:TrieNode = self.root
        for i, s_ch in enumerate(s_word):
            #move to next_node
            if s_ch in cur_node.next:
                cur_node = cur_node.next[s_ch]
                if cur_node.saved_s_idx != -1: #is end?
                    #check end s_word + saved_s is pal
                    if self.get_str_is_pal(s_word + cur_node.saved_s_word):
                        result.append([s_word_idx, cur_node.saved_s_idx])
            else:
                break
        else:
        #case 1
            for i in cur_node.pal_from_below:
                result.append([s_word_idx, i])
        
        return result

    def get_str_is_pal(self, string:str) ->bool:
        return string == string[::-1]

    def check_boundary(self, idx:int, string:str) -> bool:
        return 0 <= idx < len(string)

if __name__ == "__main__":
    words = ["abcd","dcba","lls","s","sssll"]
    # words = ["ab","ba"]

    solution = Solution()
    result = solution.palindromePairs(words)
    print(result)
