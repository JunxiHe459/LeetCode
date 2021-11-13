# 739. Daily Temperatures

做题前：

1. 


做题中：

1. Using Stack

   ```python
   class Solution:
       def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
           stack = []
           result = [0 for i in range(len(temperatures))]
           for i in range(len(temperatures)):
               curr = temperatures[i]
               while stack:
                   temp = stack[-1]
                   if curr > temp[0]:
                       result[temp[1]] = i - temp[1]
                       stack.pop()
                   else:
                       break
               stack.append((curr, i))
           return result
   ```

   

做题后：

1. 
