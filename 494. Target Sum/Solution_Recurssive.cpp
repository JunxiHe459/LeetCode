class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return sum(nums, 0, 0, target)
    }
    
    int sum(vector<int>& nums, int idx, int curr, int target)
    {
        if(idx == nums.size())
        {
            curr == target ? return 1 : return 0;
        }
        
        return sum(nums, idx + 1, curr + nums[idx], target) + sum(nums, idx + 1, curr - nums[idx], target);
    }
};