class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = nums.size();
        int idx_left = s / 2;
        int idx_right = idx_left;
        
        while(idx_left >= 0 || idx_right < s)
        {
            if(idx_left >= 0)
            {
                int next_left = idx_left - 1;
                if(idx_left == 0 || nums[idx_left] > nums[idx_left - 1])
                {
                    next_left -= 1;
                    if(idx_left == s - 1 || nums[idx_left] > nums[idx_left + 1])
                    {
                        return idx_left;
                    }
                }
                idx_left = next_left;
            }

            if(idx_right < s)
            {
                int next_right = idx_right + 1;
                if(idx_right == s - 1 || nums[idx_right] > nums[idx_right + 1])
                {
                    next_right += 1;
                    if(idx_right == 0 || nums[idx_right] > nums[idx_right - 1])
                    {
                        return idx_right;
                    }
                }
                idx_right = next_right;
            }
        }
        
        return -1;
    }
};