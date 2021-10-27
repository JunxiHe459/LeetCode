# 55. Dutch Flag Problem

做题前：

1. O(n)

   

做题中：

1. ```python
   class Solution:
       def sortColors(self, nums: List[int]) -> None:
           """
           Do not return anything, modify nums in-place instead.
           """
           left = 0 			  # （记录最后一个 0 的位置 + 1） 在哪里
           idx = 0 			  # 记录当前看到哪里了
           right = len(nums) - 1 #  （记录最后一个 2 的位置 - 1） 在哪里
           while idx <= right:
               n = nums[idx]
               if n == 0: # 如果当前是 0，那么将他和第一个 1 交换位置
                   nums[left], nums[idx] = nums[idx], nums[left]
                   # 交换位置后顺序还是对的，所以 idx 和 left 都 + 1
                   idx += 1
                   left += 1
                   continue
               if n == 1: # 如果当前是 1，那么继续往前看就行了
                   idx += 1
                   continue
               if n == 2:  # 如果当前是 2，那么将他和最后一个 2 前面的那个数交换位置
                   nums[right], nums[idx] = nums[idx], nums[right]
                   # 交换后不确定 nums[idx] 到底是几，所以不用动 idx，right - 1就行了
                   right -= 1
                   continue
           return
   ```



做题后：

1. 

