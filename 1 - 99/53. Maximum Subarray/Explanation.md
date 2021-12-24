# 56. Merge Intervals

做题前：

1. 



做题中：

1. DP
   
   ```python
   class Solution:
       def maxSubArray(self, nums: List[int]) -> int:
           dp = [0] * len(nums)
           dp[0], result = nums[0], nums[0]
           for i in range(1, len(nums)):
               if dp[i - 1] > 0:
                   dp[i] = dp[i - 1] + nums[i]
               else:
                   dp[i] = nums[i]
               result = max(result, dp[i])
           return result
   ```
   
1.  因为 DP 的时候其实只用了 arr[-1]，所以可以不用 DP，节约 space

   ```python
   class Solution:
       def maxSubArray(self, nums: List[int]) -> int:
           curr = nums[0]
           result = nums[0]
           
           for i in range(1, len(nums)):
               if curr + nums[i] > nums[i]:
                   curr += nums[i]
               else:
                   curr = nums[i]
               result = max(curr, result)
           
           return result
   ```

   

做题后：

1. 

