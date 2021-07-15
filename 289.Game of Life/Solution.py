import sys
from typing import *

class Solution:
    
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # Define 3 a 1 which is going to be 0 in the next round
        # Define 2 an 0 which is going to be 1 in the next round
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(board[i][j] == 1):
                    board[i][j] = self.check_one(board, i, j)
                else:
                    board[i][j] = self.check_zero(board, i, j)
        print(board)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(board[i][j] == 2): board[i][j] = 1
                if(board[i][j] == 3): board[i][j] = 0
        print(board)
    
    
    def check_one(self, board, i, j) -> int:
        left_up = (0 if (i == 0 or j == 0) else board[i - 1][j - 1] % 2)
        up = (0 if i == 0 else board [i - 1][j] % 2)
        right_up = (0 if (i == 0 or j == len(board[0]) - 1) else board[i - 1][j + 1] % 2)
        left = (0 if j == 0 else board[i][j - 1] % 2)
        right = (0 if (j == len(board[0]) - 1) else board[i][j+1] % 2)
        left_down = (0 if (i == len(board) - 1 or j == 0) else board[i + 1] [j - 1] % 2)
        down = (0 if i == len(board) - 1 else board[i + 1][j] % 2)
        right_down = (0 if (i == len(board) - 1 or j == len(board[0]) - 1) else board[i + 1] [j + 1] % 2)
        
        
        live_neighbor = right_down + down + left_down + right + right_up + up + left_up + left
        # print(left_up)
        # print(up)
        # print(right_up)
        # print(left)
        # print(right)
        # print(left_down)
        # print(down)
        # print(right_down)
        # print(live_neighbor)
        # print("--------")
        if(live_neighbor < 2 or live_neighbor > 3):
            return 3
        else:
            return 1
    
    def check_zero(self, board, i, j) ->int:
        left_up = (0 if (i == 0 or j == 0) else board[i - 1][j - 1] % 2)
        up = (0 if i == 0 else board [i - 1][j] % 2)
        right_up = (0 if (i == 0 or j == len(board[0]) - 1) else board[i - 1][j + 1] % 2)
        left = (0 if j == 0 else board[i][j - 1] % 2)
        right = (0 if (j == len(board[0]) - 1) else board[i][j+1] % 2)
        left_down = (0 if (i == len(board) - 1 or j == 0) else board[i + 1] [j - 1] % 2)
        down = (0 if i == len(board) - 1 else board[i + 1][j] % 2)
        right_down = (0 if (i == len(board) - 1 or j == len(board[0]) - 1) else board[i + 1] [j + 1] % 2)
        
        live_neighbor = right_down + down + left_down + right + right_up + up + left_up + left
        if(live_neighbor == 3 ):
            return 2
        else:
            return 0
    



s = Solution()
board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
s.gameOfLife(board)
