class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = {}
        # visited = [[False for j in range(len(board[0]))] for i in range(len(board))]
        for x in range(len(board)):
            for y in range(len(board[0])):
                if self.DFS(board, visited, word, x, y, 0):
                    return True
        return False
    
    
    def DFS(self, board, visited, word, x, y, idx) -> bool:
        if(idx >= len(word)):
            return True
        
        if(x >= len(board) or x < 0 or y >= len(board[0]) or y < 0):
            return False
        
        if(board[x][y] != word[idx] or visited.get((x, y))):
            return False
        
        # visited[x][y] = True
        visited[(x, y)] = True
        idx += 1
        
        down = self.DFS(board, visited, word, x + 1, y, idx)
        up = self.DFS(board, visited, word, x - 1, y, idx)
        left = self.DFS(board, visited, word, x, y - 1, idx)
        right = self.DFS(board, visited, word, x, y + 1, idx)
        
        # visited[x][y] = False
        visited[(x, y)] = False
        
        return down or up or left or right
    