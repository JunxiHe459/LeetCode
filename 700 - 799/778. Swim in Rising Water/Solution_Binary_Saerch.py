class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        left = 0
        right = n ** 2 - 1
        
        while(left < right):
            mid = (left + right) // 2
            visited = [[0 for i in range(n)] for j in range(n)]
            if(self.DFS(grid, visited, mid, 0, 0)):
                right = mid
            else:
                left = mid 
        
        return left
    
    def DFS(self, grid, visited, level, i, j):
        # print("here")
        if(i < 0 or j < 0 or i >= len(grid) or j >= len(grid) or grid[i][j] > level or visited[i][j] == 1):
            return False
        else:
            # print(i, j)
            visited[i][j] = 1
            if(visited[-1][-1] == 1):
                return True
            return self.DFS(grid, visited, level, i + 1, j) or \
                self.DFS(grid, visited, level, i - 1, j) or \
                self.DFS(grid, visited, level, i, j + 1) or \
                self.DFS(grid, visited, level, i, j - 1)