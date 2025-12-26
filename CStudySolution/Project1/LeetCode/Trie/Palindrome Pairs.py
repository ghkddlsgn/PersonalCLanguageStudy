class TrieNode:
    def __init__(self,ch:str,ch_idx:int) -> None:
        self.ch:str = ch
        self.ch_idx_from_back:int = ch_idx
        self.stored_word = ""
        self.stored_word_idx:int = -1
        self.next:dict[str, TrieNode] = {}
        self.palindrom_from_here_idx:list[int] = []
    
    def check_palindrome(self, word:str, word_idx:int):
        if len(word) > word_idx+1: return
        target_string:str = word[word_idx+1:]
        if target_string == target_string[::-1]:
            self.palindrom_from_here_idx.append(word_idx)
            print(f"ch:{self.ch} word:{word}, new word_idx:{word_idx}, list:{self.palindrom_from_here_idx}")


class Solution:
    def __init__(self) -> None:
        self.root = TrieNode("root", -1)

    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        
        result:list[list[int]] = []

        for idx, word in enumerate(words):
            self.add_node(word, idx)
        
        for idx, word in enumerate(words):
            pairings = self.search_palindrome(word, idx)
            result.extend(pairings)
        return result
        

    
    def add_node(self, word:str, word_idx:int):
        inverse_word = word[::-1]
        cur_node = self.root
        for idx, ch in enumerate(inverse_word):
            if ch not in cur_node.next:
                new_node = TrieNode(ch, idx)
                cur_node.next[ch] = new_node
            
            cur_node = cur_node.next[ch]
            cur_node.check_palindrome(word, word_idx)
        else:
            cur_node.stored_word = word
            cur_node.stored_word_idx = word_idx
    
    def search_palindrome(self, word:str, word_idx:int) -> list[list[int]]:
        #case 1 : word len <= trie len
            #return node's palindrome index
        #case 2 : word len == trie len
            #return node's palindrome index
        #case 3 : word len >= trie len
            #check remain chunk is palindrome

        result:list[list[int]] = []
        cur_node = self.root
        for idx, ch in enumerate(word):
            if ch in cur_node.next:
                cur_node = cur_node.next[ch]
                if cur_node.stored_word_idx != -1:
                    result.append([idx, cur_node.stored_word_idx])
            else:
                #case 3
                remain_str = word[idx:]
                if self.is_palindrome(remain_str):
                    result.append([word_idx, cur_node.palindrom_from_here_idx[0]])
                    return result
                else:
                    return []
        else:
            #case 1,2 check
            result = []
            for i in cur_node.palindrom_from_here_idx:
                result.append([word_idx, i])
            return result

    def is_palindrome(self, string:str) -> bool:
        return string == string[::-1]

if __name__ == "__main__":
    # words = ["abcd","dcba","lls","s","sssll"]
    words = ["ab","ba"]

    solution = Solution()
    result = solution.palindromePairs(words)
    print(result)
