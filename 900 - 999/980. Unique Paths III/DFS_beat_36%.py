class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start_x = -1
        start_y = -1
        blocked = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    start_x = i
                    start_y = j
                if grid[i][j] == -1:
                    blocked += 1
        total = len(grid) * len(grid[0]) - blocked
        return self.path(grid, start_x, start_y, 1, total)
        
    def path(self, grid, x, y, curr, total) -> int:
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
            return 0
        if grid[x][y] == 2 and curr == total:
            return 1
        if grid[x][y] <= -1:
            return 0
        grid[x][y] -= 3
        
        up    = self.path(grid, x - 1, y, curr + 1, total)
        down  = self.path(grid, x + 1, y, curr + 1, total)
        left  = self.path(grid, x, y - 1, curr + 1, total)
        right = self.path(grid, x, y + 1, curr + 1, total) 
        
        grid[x][y] += 3
        return up + down + left + right