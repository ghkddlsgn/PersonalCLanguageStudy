class TrieNode:
    def __init__(self, parent_node:'TrieNode', ch:str, ch_idx:int, store_words_count:int) -> None:
        self.ch:str = ch
        self.next:dict = {}
        self.ch_idx:int = ch_idx
        self.stored_word:str = ''
        self.parent_node:TrieNode = parent_node
        self.store_words_count:int = store_words_count #it represent stored word number from this node and below

class Solution:
    def __init__(self) -> None:
        self.board:list[list[str]] =[]
        self.words:set[str] = set()
        self.found_words:set[str] = set()
        self.root = TrieNode(None, "root", -1, -1)

    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        self.board = board
        self.words = set(words)
        
        for word in self.words:
            self.add_string(word)
        
        for row_idx, row in enumerate(board):
            for col_idx, ch in enumerate(row):
                self.dfs(self.root, row_idx, col_idx)

        return list(self.found_words)
    
    def add_string(self, word:str):
        cur_node = self.root
        for idx, ch in enumerate(word):
            if ch not in cur_node.next:
                new_node = TrieNode(cur_node, ch, idx, 0) #create new node
                cur_node.next[ch] = new_node #make new node as child
            cur_node = cur_node.next[ch]
            cur_node.store_words_count = cur_node.store_words_count + 1
            
        cur_node.stored_word = word
    
    def reduce_stored_word_count(self, node:TrieNode):
        #if there's no words below nodes, then remove those nodes so we don't search it again.
        cur_node = node
        while(cur_node != self.root):
            cur_node.store_words_count = cur_node.store_words_count - 1
            parent_node = cur_node.parent_node
            if cur_node.store_words_count == 0:
                del parent_node.next[cur_node.ch]
            cur_node = parent_node

    
    def get_adj_ch(self, from_i:int, from_j:int) -> list[tuple[int,int]]:
        result:list[tuple[int,int]] = []
        for i,j in [(from_i - 1, from_j),(from_i + 1, from_j),(from_i, from_j - 1),(from_i, from_j + 1)]:
            if 0 <= i < len(self.board) and 0 <= j < len(self.board[0]): result.append((i,j))
        return result

    def dfs(self, cur_node:TrieNode, i:int, j:int):
        cur_char = self.board[i][j]
        if cur_node == self.root and cur_char in self.root.next:
                cur_node = self.root.next[cur_char]

        if self.board[i][j] != cur_node.ch: return #skip if ch is not match
        if cur_node.stored_word != '': #we found new word?
            self.found_words.add(cur_node.stored_word) # if we found new stored word, store that word
            cur_node.stored_word = ''
            self.reduce_stored_word_count(cur_node) #since we found word, reduce word count.
        
        self.board[i][j] = '#'
        self.print_board()
        adj_indices = self.get_adj_ch(i,j)
        for next_i, next_j in adj_indices:
            next_ch = self.board[next_i][next_j]
            if next_ch in cur_node.next:
                self.dfs(cur_node.next[next_ch], next_i, next_j)

        self.board[i][j] = cur_node.ch
    
    def print_board(self):
        print("\n======================")
        for row in self.board:
            print(' '.join(row))
        print("======================")


if __name__ == "__main__":

    s = Solution()
    
    board_custom = [
        ["o","a","b","n"],
        ["o","t","a","e"],
        ["a","h","k","r"],
        ["a","f","l","v"]
    ]
    words_custom = ["oa","oaa"]
    result_custom = s.findWords(board_custom, words_custom)
    print("Custom Test Case Result:", result_custom)



    
    # # Test Case 1
    # board = [
    #     ["o","a","a","n"],
    #     ["e","t","a","e"],
    #     ["i","h","k","r"],
    #     ["i","f","l","v"]
    # ]
    # words = ["oath","pea","eat","rain"]
    # # words = ["oath"]
    
    # result = s.findWords(board, words)
    # print("Test Case 1 Result:", result) 
    # Expected: ["eat","oath"] (order may vary)

    # # Test Case 2 (Small)
    # board2 = [["a","b"],["c","d"]]
    # words2 = ["abcb"]
    # print("Test Case 2 Result:", s.findWords(board2, words2)) 
    # # Expected: []