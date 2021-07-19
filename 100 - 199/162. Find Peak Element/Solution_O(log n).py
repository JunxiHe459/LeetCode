class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        if(len(nums) == 1):
            return 0
        
        if(nums[1] < nums[0]):
            return 0
        if(nums[right - 1] < nums[right]):
            return right
        
        while(left < right):
            mid = (left + right) // 2
            
            if(nums[mid] < nums[mid + 1]):
                left = mid + 1
            else:
                right = mid
        return left
            