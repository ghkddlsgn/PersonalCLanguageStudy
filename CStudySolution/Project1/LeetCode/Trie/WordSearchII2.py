from typing import Optional

class TrieNode():
    def __init__(self, ch:str = "", str_idx = -1) -> None:
        self.ch:str = ch
        self.str_idx:int = str_idx
        self.next:list[TrieNode | None] = [None] * 26
        self.is_end:bool = False
        self.stored_str:str = ""

class Solution:
    def __init__(self) -> None:
        self.board: list[list[str]] = []
        self.remain_words: set[str] = set()
        self.find_words:set[str] = set()
        self.root:TrieNode = TrieNode("root")

    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        self.board = board
        self.remain_words = set(words)
        self.debug_print_board()
        for word in words:
            self.add_string(word)
        
        for word in self.remain_words:
            if word in self.find_words: continue #if we already found this word from other dfs, skip

            start_indices = self.get_idices_for_ch(word[0])
            for i,j in start_indices:
                next_idx = self.convert_ch_to_idx(word[0])
                self.dfs_preorder_searching(i,j, self.root.next[next_idx])
                if word in self.find_words: break #if we already found, just skip for this word
        
        return list(self.find_words)
    
    def get_idices_for_ch(self, ch:str):
        result:list[tuple[int, int]] = []
        for i, board_row in enumerate(self.board):
            for j, board_ch in enumerate(board_row):
                if (board_ch == ch): result.append((i,j))
        
        return result

    def add_string(self, word:str):
        cur_node = self.root
        for i, ch in enumerate(word):
            key_idx = self.convert_ch_to_idx(ch)
            if cur_node.next[key_idx] == None: #need to create new node?
                new_node = TrieNode(ch, i)
                cur_node.next[key_idx] = new_node
            cur_node = cur_node.next[key_idx]
        else:
            cur_node.is_end = True
            cur_node.stored_str = word

    def convert_ch_to_idx(self, ch:str):
        idx:int = ord(ch) - ord('a')
        return idx

    def dfs_preorder_searching(self, i_idx:int, j_idx:int, cur_node:Optional[TrieNode] = None):
        if cur_node == None: cur_node = self.root

        cur_char = self.board[i_idx][j_idx]
        self.board[i_idx][j_idx] = "#"
        self.debug_print_board()
        #if i found word, add word to find_words
        if cur_node.is_end:
            self.find_words.add(cur_node.stored_str)

        next_search:dict[str, list[tuple[int, int]]] = dict()
        #check is there any adj str i can go (dfs)
        for i,j in self.get_adj_block(i_idx, j_idx):
            char = self.board[i][j]
            if char == '#': continue
            next_search.setdefault(char, []).append((i,j))

        for child_node in cur_node.next:
            if child_node == None: continue
            child_ch = child_node.ch
            child_ch_idx = self.convert_ch_to_idx(child_ch)
            if child_ch in next_search:
                for i,j in next_search[child_ch]:
                    self.dfs_preorder_searching(i, j, child_node)

        #return mark # to normal str        
        self.board[i_idx][j_idx] = cur_char
    
    def get_adj_block(self, i_idx:int, j_idx:int) -> list[tuple[int,int]]:
        result_idices:list[tuple[int, int]] = []
        for i, j in [(i_idx - 1, j_idx), (i_idx + 1, j_idx), (i_idx, j_idx -1), (i_idx, j_idx + 1)]:
            if 0 <= i <= len(self.board) - 1 and 0 <= j <= len(self.board[0]) - 1:            
                result_idices.append((i,j))
        
        return result_idices
    
    def debug_print_board(self):
        print("\n--- Board State ---")
        for row in self.board:
            print("[ ", end="")
            for ch in row:
                print(f"{ch} ", end="")
            print("]") # Newline after each row
        print("-------------------")

if __name__ == "__main__":
    s = Solution()
    
    # Test Case 1
    board = [
        ["o","a","a","n"],
        ["e","t","a","e"],
        ["i","h","k","r"],
        ["i","f","l","v"]
    ]
    words = ["oath","pea","eat","rain"]
    # words = ["oath"]
    
    result = s.findWords(board, words)
    print("Test Case 1 Result:", result) 
    # Expected: ["eat","oath"] (order may vary)

    # # Test Case 2 (Small)
    # board2 = [["a","b"],["c","d"]]
    # words2 = ["abcb"]
    # print("Test Case 2 Result:", s.findWords(board2, words2)) 
    # # Expected: []