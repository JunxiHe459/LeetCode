class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> re(rowIndex + 1, 0);
        for(int i = 0; i <= rowIndex; ++i)
        {
            re[i] = get_value(rowIndex, i);
        }
        return re;
    }
    
    int get_value(int r, int i)
    {
        if(i == 0)
        {
            return 1;
        }
        
        if(i == r)
        {
            return 1;
        }
        
        return get_value(r - 1, i - 1) + get_value(r - 1, i);
    }
};