# 739. Daily Temperatures

做题前：

1. 


做题中：

1. Using Stack O(n) time O(n) space complexity

   ```python
   class Solution:
       def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
           result = [0 for i in range(len(temperatures))]
           stack = []
           for i in range(len(temperatures)):
               while stack and temperatures[stack[-1]] < temperatures[i]:
                   idx = stack.pop()
                   result[idx] = i - idx
               stack.append(i)
           return result
   ```
   
1. O(n) time O(1) space complexity

   ```
   ```
   
   

做题后：

1. 
