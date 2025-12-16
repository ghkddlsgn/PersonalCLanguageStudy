from typing import Optional

class TrieNode():
    def __init__(self, ch = "") -> None:
        self.ch: str = ch
        self.next_nodes: dict[str, TrieNode] = {}
        self.is_end:bool = False

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        if len(word) == 0: return

        cur_node = self.root
        for ch in word:
            if ch not in cur_node.next_nodes:
                new_node = TrieNode(ch)
                cur_node.next_nodes[ch] = new_node
            
            cur_node = cur_node.next_nodes[ch]
        
        cur_node.is_end = True

    def search(self, word: str, cur_node:Optional[TrieNode] = None) -> bool:
        if len(word) == 0:return True
        if cur_node == None: cur_node = self.root

        for idx, ch in enumerate(word):
            # if we meet . then search it recursively. so recurse function will handle the search result
            if ch == ".":
                if len(word)-1 == idx: #is it last char?
                    for node in cur_node.next_nodes.values():
                        if node.is_end:
                            return True
                    else:
                        return False

                remain_word_chunk = word[idx+1:]
                
                for idx, key in enumerate(cur_node.next_nodes):
                    if self.search(remain_word_chunk, cur_node.next_nodes[key]):
                        return True
                
                return False
                            
            #if we meet general ch, then just handle in for loop
            if ch not in cur_node.next_nodes:
                return False
            else:
                cur_node = cur_node.next_nodes[ch]
        
        return cur_node.is_end

        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)


if __name__ == "__main__":
    # Example usage
    wd = WordDictionary()
    print(wd.addWord("at"))        # None
    print(wd.addWord("and"))       # None
    print(wd.addWord("an"))        # None
    print(wd.addWord("add"))       # None
    print(wd.addWord("bat"))       # None
    print(wd.search("a"))          # False
    print(wd.search(".at"))        # False
    print(wd.search(".at"))        # True
    print(wd.search("an."))        # True
    print(wd.search("a.d."))       # False
    print(wd.search("b."))         # False
    print(wd.search("a.d"))        # False
    print(wd.search("."))          # False