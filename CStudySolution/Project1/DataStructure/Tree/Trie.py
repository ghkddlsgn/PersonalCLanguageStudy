class TrieNode:
    def __init__(self, ch:str = "") -> None:
        self.ch = ch
        self.next_node:dict[str, TrieNode] = {}
        self.is_end:bool = False



class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current_node:TrieNode = self.root
        for ch in word:
            if ch not in current_node.next_node:
                current_node.next_node[ch] = TrieNode(ch)
            
            current_node = current_node.next_node[ch]
        
        current_node.is_end = True
                
    def search(self, word: str) -> bool:
        current_node = self.root
        for ch in word:
            if ch not in current_node.next_node: return False            
            current_node = current_node.next_node[ch]        
        else:
            return True if current_node.is_end else False

    def startsWith(self, prefix: str) -> bool:
        current_node = self.root
        for ch in prefix:
            if ch not in current_node.next_node: return False
            current_node = current_node.next_node[ch]
        else:
            return True
        

a = Trie()

print(a.insert("a"))
print(a.search("a"))
print(a.startsWith("a"))



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)