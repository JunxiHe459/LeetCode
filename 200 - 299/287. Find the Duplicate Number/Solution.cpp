class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] < mid + 1)
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};