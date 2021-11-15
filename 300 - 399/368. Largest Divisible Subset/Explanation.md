# 368. Largest Divisible Subset

做题前：

1. 这题 TM 的居然用 DP？



做题中：

1.  beat 80%

   ```python
   class Solution:
       def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
           # Step 1: 先排序
           nums.sort()
           
           # Step 2: DP 算出 result 的最大长度
           dp = [(1, i) for i in range(len(nums))]
           for i in range(len(nums)):
               curr = nums[i]
               inc = dp[i][0]
               for j in range(i + 1, len(nums)):
                   if nums[j] % curr == 0 and inc + 1 > dp[j][0]:
                               dp[j] = (inc + 1, i)
           
           # Step 3: 找到最大的那个 idx
           idx = -1
           max_ = -1
           for i in range(len(dp)):
               if dp[i][0] > max_:
                   max_ = dp[i][0]
                   idx = i
                   
           # Step 4: 根据 idx 推出整个 result   
           result = []
           while idx != dp[idx][1]:
               result.append(nums[idx])
               idx = dp[idx][1]
           result.append(nums[idx])
           
           # Step 5: Problem Solved
           return result
                   
   ```

   1. **==Inspiration from==**：

   ![image](/Users/junxihe/Desktop/LeetCode/300 - 399/374. Guess Number Higher or Lower copy/image_1592042710.png)

做题后：

1. 

