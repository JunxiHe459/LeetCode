class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in [0, len(board[0]) - 1]:
                self.check(board, i, j)
        for i in range(len(board[0])):
            for j in [0, len(board) - 1]:
                self.check(board, j, i)
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '!':
                    board[i][j] = 'O'
        return
    
    def check(self, board, i, j):
        if board[i][j] != 'O':
            return
        board[i][j] = '!'
        if i > 0:
            self.check(board, i - 1, j)
        if i < len(board) - 1:
            self.check(board, i + 1, j)
        if j > 0:
            self.check(board, i, j - 1)
        if j < len(board[0]) - 1:
            self.check(board, i, j + 1)