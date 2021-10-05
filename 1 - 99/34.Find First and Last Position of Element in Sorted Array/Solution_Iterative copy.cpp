class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result = {-1, -1};
        if(size(nums) == 0) {return result;}
        int left = find_left(nums, target);
        if (left == -1) {return result;}
        int right = find_right(nums, target);
        result[0] = left;
        result[1] = right;
        return result;
    }
    
    int find_left(vector<int>& nums, int target)
    {
        int left = 0;
        int right = size(nums) - 1;
        int index = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] < target)
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
            
            if(nums[mid] == target) {index = mid;}
        }
        
        return index;
    }
    
    int find_right(vector<int>& nums, int target)
    {
        int left = 0;
        int right = size(nums) - 1;
        int index = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] <= target)
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
            
            if(nums[mid] == target) {index = mid;}
        }
        
        return index;
    }
};