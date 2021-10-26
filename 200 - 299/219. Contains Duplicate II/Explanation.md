# 217. Contains Duplicate II

做题前：

1. Easy



做题中：

1. defaultdict, YYDS

   ```python
   from collections import defaultdict
   class Solution:
       def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
           if k == 0:
               return False
           d = defaultdict(lambda:-1)
           for i in range(len(nums)):
               n = nums[i]
               if d[n] != -1 and i - d[n] <= k:
                   return True
               d[n] = i     
           return False
   ```
   
   



做题后：

1. 

