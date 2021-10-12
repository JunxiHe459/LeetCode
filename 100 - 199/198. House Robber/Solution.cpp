class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int time = 0;
        
        while(1)
        {
            bool change = false;
            for(int i = 0; i < grid.size(); ++i)
            {
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    if(grid[i][j] != 1)
                    {
                        continue;
                    }
                    
                    bool rotten = check_rotten(grid, i, j);
                    if(rotten)
                    {
                        grid[i][j] = 3;
                        change = true;
                    }
                }
            }
            
            if(!change)
            {
                break;
            }
            
            for(int i = 0; i < grid.size(); ++i)
            {
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    if(grid[i][j] == 3)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        
            time += 1;
        }
        
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return time;

        
    }
    
    bool check_rotten(vector<vector<int>>& grid, int i, int j)
    {
        // Left
        if(i > 0 && grid[i - 1][j] == 2)
        {
            return true;
        }
        
        // Up
        if(j > 0 && grid[i][j - 1] == 2)
        {
            return true;
        }
        
        // Right
        if(j < grid[0].size() - 1 && grid[i][j + 1] == 2)
        {
            return true;
        }
        
        // Down
        if(i < grid.size() - 1 && grid[i + 1][j] == 2)
        {
            return true;
        }
        
        return false;
    }
};