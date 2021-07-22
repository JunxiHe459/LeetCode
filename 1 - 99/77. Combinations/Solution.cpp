class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> re;
        vector<int> curr;
        DFS(re, curr, n, k, 1);
        return re;
    }
    
    void DFS(vector<vector<int>> &re, vector<int> &curr, int n, int k, int idx)
    {
        if(curr.size() == k)
        {
            re.push_back(curr);
            return;
        }
        
        for(int i = idx; i <= n; i++)
        {
            curr.push_back(i);
            DFS(re, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};