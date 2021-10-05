class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = size(mat);
        int n = size(mat[0]);
        vector<int> result;
        for(int i = 0; i < m + n - 1; i++)
        {
            if(i % 2)
            {
                int y = (i < n) ? i : n - 1;
                int x = (i - n + 1 > 0) ? i - n + 1 : 0;
                while(x < m && y >= 0)
                {
                    // cout << x << ", " << y << endl;
                    result.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            else
            {
                // Find all correct starting index of each diagonal traverse
                int y = (i - m + 1 > 0) ? i - m + 1 : 0;
                int x = (i < m) ? i : m - 1;
                while(y < n && x >= 0)
                {
                    // cout << x << ", " << y << endl;
                    result.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return result;
    }
};