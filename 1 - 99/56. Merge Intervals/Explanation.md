# 56. Merge Intervals

做题前：

1. 



做题中：

1. ```python
   class Solution:
       def merge(self, intervals: List[List[int]]) -> List[List[int]]:
           result = [] 
           intervals.sort(key=lambda x:x[0])
           i = 0
           
           while i < len(intervals):
               j = i + 1
               temp = intervals[i][1]
               while j < len(intervals) and temp >= intervals[j][0]:
                   temp = max(temp, intervals[j][1])
                   j += 1
               result.append([intervals[i][0], temp])
               i = j
               
           return result
   ```

1. 



做题后：

1. 

