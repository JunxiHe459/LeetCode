class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> re(rowIndex + 1, 0);
        re[0] = 1;
        for(int i = 1; i <= rowIndex; ++i)
        {
            for(int j = i; j > 0; --j)
            {
                re[j] += re[j - 1];
            }
        }
        
        return re;
        
    }
};