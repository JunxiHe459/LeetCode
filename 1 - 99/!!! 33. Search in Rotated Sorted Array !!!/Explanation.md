# 33. Search in rotated sorted array

做题前：

1. 先找到 rotated 多少，再通过 rotated 计算 real_mid 见 思路二
2. 还有一种无敌的方法，见下面的 **思路一**



做题中：

1. **==第一种思路==**

   假设我们有 [4, 5, 6, 1, 2, 3]

   首先这个 array 可以被分为两个小 array -> [4, 5, 6] 和 [1, 2, 3]

   这两个小 array 满足 2 个条件：

   1. **每个小 array 都是 asc sorted 的**
   2. **左边那个 array 里面的每一个都比 右边那个 array 大**

   通过以上分析，这个题存在 **==3==** 种情况：

   首先我们先按照 left = 0, right = len(nums), mid = right - (right  - left) / 2 得到 mid

   1. mid 和 target 都在一边，不管是 左array 还是 右array 

      这种情况下：因为 左array 和 右array 都是 sorted，直接二分法即可

   2. mid 在 左array，target 在 右array

      这种情况下：mid 在 target 的左边，需要让 left = mid + 1

   3. mid 在 右array，target 在 左array

      这种情况下：mid 在 target 的右边，需要让 right = mid - 1

   ```python
   class Solution:
       def search(self, nums: List[int], target: int) -> int:
           left = 0
           right = len(nums)
           while left < right:
               mid = (left + right) >> 1
               # 情况一：mid 和 target 都在一边
               if (nums[mid] < nums[0] and target < nums[0]) or (nums[mid] >= nums[0] and target >= nums[0]):
                   if nums[mid] > target:
                       right = mid
                   elif nums[mid] < target:
                       left = mid + 1
                   else:
                       return mid
               # 情况二：mid 在左，target 在右
               elif nums[mid] > nums[0] and target < nums[0]:
                   left = mid + 1
               # 情况三：mid 在右，target 在左
               else:
                   right = mid
           return -1
   ```

   以上代码可以简写为：

   ```python
   def search(self, nums, target):
           lo, hi = 0, len(nums)
   
           while lo < hi:
               mid = (lo + hi) / 2
               # 情况 1
               if (nums[mid] < nums[0]) == ( target < nums[0]):
                   if (nums[mid] < target):
                       lo = mid + 1
                   elif (nums[mid] > target):
                       hi = mid
                   else:
                       return mid
               # 情况 2
               elif target < nums[0]:
                   lo = mid + 1
               # 情况 3
               else:
                   hi = mid
   
           return -1
   ```

   

2. **==第二种思路==**

   ```python
   class Solution:
       def search(self, nums: List[int], target: int) -> int:
           if len(nums) == 1:
               return (nums[0] == target) - 1
           left = 0
           right = len(nums) - 1
           while left <= right:
               mid = (left + right) >> 1
               if nums[mid] > nums[right]:
                   left = mid + 1
               else:
                   if nums[mid] < nums[0]:
                       right = mid - 1
                   else:
                       left = mid + 1                 
           pivot = left
           
           left = 0
           right = len(nums)
           while left <= right:
               mid = (left + right) >> 1
               real_mid = (mid + pivot) % len(nums)
               if nums[real_mid] == target:
                   return real_mid
               elif nums[real_mid] > target:
                   right = mid - 1
               else:
                   left = mid + 1
           return -1
   ```

   



做题后：

1. 

