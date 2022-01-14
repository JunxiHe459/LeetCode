# 252. Meeting Rooms

做题前：

1. 
   



做题中：

1. ```python
   class Solution:
       def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
           intervals.sort(key=lambda x:x[1])
           end = -1
           for i in intervals:
               if end > i[0]:
                   return False
               else:
                   end = i[1]
           return True
   ```
   
1. ```python
   class Solution:
       def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
           intervals.sort(key=lambda x:x[0])
           
           for i in range(1, len(intervals)):
               if intervals[i][0] < intervals[i - 1][1]:
                   return False
               
           return True
   ```

1. 



做题后：

1. 

