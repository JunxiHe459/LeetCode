# 452. Minimum Number of Arrows to Burst Balloons

做题前：

1. 这道题就是算 Overlapping 的次数嘛。用的是 Greedy Algorithm

做题中：

1. ```python
      class Solution:
          def findMinArrowShots(self, points: List[List[int]]) -> int:
              points.sort(key=lambda x:x[1])
              curr = points[0][1]
              count = 1
              for i in range(1, len(points)):
                  # 如果 curr >= points[i][0]，则证明是 Overlap 的，直接 continue
                  if curr >= points[i][0]:
                      continue
                  # 否则就不是 Overlap 的，curr 就要往右移 curr，并且 count + 1
                  curr = points[i][1]
                  count += 1
              return count
      ```
      
2. 

做题后：

1.  

