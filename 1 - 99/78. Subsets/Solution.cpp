class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> curr;
        DFS(re, curr, nums, 0);
        return re;
    }
    
    void DFS(vector<vector<int>> &re, vector<int> &curr, vector<int>& nums, int idx)
    {
        re.push_back(curr);
        
        if(idx == nums.size())
        {
            return;
        }
        
        for(int i = idx; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            DFS(re, curr, nums, i + 1);
            curr.pop_back();
        }
    }
};