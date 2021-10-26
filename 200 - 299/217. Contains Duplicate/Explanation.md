# 217. Contains Duplicate

做题前：

1. Easy



做题中：

1. 用 set 比用 dict 好

   ```python
   class Solution:
       def containsDuplicate(self, nums: List[int]) -> bool:
           s = set()
           for i in nums:
               if i in s:
                   return True
               s.add(i)
           return False
   ```

   



做题后：

1. 

