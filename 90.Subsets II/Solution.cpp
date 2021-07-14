class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Set up
        vector<vector<int>> re;
        vector<int> curr;

        /// Sort the nums
        sort(nums.begin(), nums.end());

        // DFS recursion
        DFS(re, curr, nums, 0);

        return re;
    }
    
    void DFS(vector<vector<int>> &re, vector<int> &curr, vector<int>& nums, int idx)
    {
        
        re.push_back(curr);

        // Exit condition
        if(nums.size() == 0)
        {
            return;
        }
        
        // Check for duplicates
        set<int> s;
        // int prev = -123456789;

        // Classic DFS recursion
        for(int i = idx; i < nums.size(); ++i)
        {
            int temp = nums[i];
            if(s.find(temp) != s.end())
            {
                continue;
            }
            // if(prev == temp)
            // {
            //     continue;
            // }

            s.insert(temp);
             // prev = temp;

            curr.push_back(temp);
            DFS(re, curr, nums, i + 1);
            curr.pop_back();
        }
    }
    
};