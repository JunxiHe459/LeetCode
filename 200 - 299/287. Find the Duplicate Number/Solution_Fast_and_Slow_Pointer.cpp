class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return -1;
        }
        
        int fast = nums[nums[0]];
        int slow = nums[0];
        
        while(fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        
        int restart = 0;
        while(restart != slow)
        {
            slow = nums[slow];
            restart = nums[restart];
        }
        
        return restart;
    }
};