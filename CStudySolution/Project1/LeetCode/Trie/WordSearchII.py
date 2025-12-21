class TrieNode():
    def __init__(self, ch='', idx= -1) -> None:
        self.ch:str = ch
        self.idx:int = idx
        self.next_node:list[TrieNode | None] = [None]*26

class Solution:
    def __init__(self) -> None:
        self.root:TrieNode = TrieNode()
        self.board:list[list[str]] = []
        self.board_mask:list[list[bool]] = []
        self.words:list[str] = []
    
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        self.board = board
        self.board_mask = [[False for _ in range(len(self.board[0]))] for _ in range(len(self.board))]
        self.words = words
        for word in words:
            self.add_trie(word)
        
    def dfs(self, str_idx:int, i:int, j:int):
        search_targets:list[str] = self.get_chars_on_idx(str_idx)
        temp_ch:str = self.board[i][j]
        self.board[i][j] = '-'

        next_search_idx = self.get_adjacent_char_idices(i,j)
        for next_i,next_j in next_search_idx:
            if self.board[next_i][next_j] == '-': continue
            if self.board[next_i][next_j] not in search_targets: continue
            self.dfs(str_idx + 1, next_i, next_j)
        
        self.board[i][j] = temp_ch


    
    def add_trie(self, word):
        cur_node = self.root
        for idx, ch in enumerate(word):
            hash_idx = self.get_idx_key(ch)
            if cur_node.next_node[hash_idx] == None:
                new_node = TrieNode(ch, idx)
                cur_node.next_node[hash_idx] = new_node
            cur_node = cur_node.next_node[hash_idx]

    def get_chars_on_idx(self, target_str_idx):
        result:list[str] = []
        cur_nodes:list[TrieNode] = [self.root]
        for i in range(target_str_idx + 1):
            new_nodes:list[TrieNode] = []
            for node in cur_nodes:
                for childnode in node.next_node:
                    if childnode: new_nodes.append(childnode)
            cur_nodes = new_nodes
        
        for node in cur_nodes:
            result.append(node.ch)
        return result

    def get_adjacent_char_idices(self, i, j) -> list[tuple[int,int]]:
        result:list[tuple[int,int]] = []        
        for i_adj, j_adj in [(i-1,0),(i+1,j),(i,j-1),(i,j+1)]:
            if i_adj >= len(self.board) or j_adj >= len(self.board[0]): continue
            if j_adj<0 or i_adj< 0:continue
            result.append((i_adj,j_adj))
        return result
    
    def get_idx_key(self, ch) -> int:
        return ord(ch) - ord('a')
