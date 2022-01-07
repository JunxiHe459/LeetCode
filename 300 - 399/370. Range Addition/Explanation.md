# 370. Range Addition

做题前：

1. 



做题中：

1. Prefix Sum

   ```python
   class Solution:
       def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
           result = [0] * length
           for start, end, value in updates:
               result[start] += value
               if end + 1 < length:
                   result[end + 1] -= value 
           for i in range(1, length):
               result[i] += result[i - 1]
           return result
   ```

   



做题后：

1. 

