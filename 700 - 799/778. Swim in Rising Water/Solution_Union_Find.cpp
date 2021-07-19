class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> index(n * n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                index[grid[i][j]] = i * n + j;
            }
        }
        
        vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        Solution::UnionFind uf(n * n);
        for(int i = 0; i < n * n; i++)
        {
            int x = index[i] / n;
            int y = index[i] % n;
            
            for(auto d : dir)
            {
                int new_x = x + d[0];
                int new_y = y + d[1];
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] <= i)
                {
                    uf.merge(new_x * n + new_y, index[i]);
                }
                
                if(uf.connected(0, n * n -1)) {
                    return i;
                }
            }
        }
        return -1;
    }
    
    class UnionFind{
        public:
        vector<int> parent;
        
        public:
        UnionFind(int n) {
            parent = vector<int>(n, 0);
            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }
        
        int root(int n) {
            int temp = n;
            while(parent[temp] != temp)
            {
                temp = parent[temp];
            }
            parent[n] = temp;
            return temp;
        }
        
        bool connected(int n1, int n2)
        {
            return root(n1) == root(n2);
        }
        
        void merge(int n1, int n2) {
            if(connected(n1, n2)) return;
            parent[root(n1)] = root(n2);
            
        }
        
    };
};