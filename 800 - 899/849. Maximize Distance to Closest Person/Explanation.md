# 849. Maximize Distance to Closest Person

做题前：

1. One Pass
1. 如果想要 Max Distance，那就需要找到最大的空着的区间
1. 注意开头区间和结尾区间的特殊处理

做题中：

1. ```python
   class Solution:
       def maxDistToClosest(self, seats: List[int]) -> int:
           start, end = -1, 0
           distance = -1
           
           while end < len(seats):
               if seats[end] == 1:
                   # 开头区间的特殊处理
                   if start < 0:
                       distance = end * 2
                   else:
                       distance = max(distance, end - start)
                   start = end
                   end = start + 1
               else:
                   end += 1
           # 结尾区间的特殊处理 (end - start - 1)
           return max(distance // 2, end - start - 1)
   ```



做题后：

1. 

