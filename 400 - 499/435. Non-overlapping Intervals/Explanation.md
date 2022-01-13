# 435. Non-overlapping Intervals

做题前：

1. 用的还是 Greedy Algorithm

做题中：

1. ```python
      class Solution:
          def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
              intervals.sort(key=lambda x:x[1])
              count = 0
              curr = intervals[0][1]
              
              for i in range(1, len(intervals)):
                  # 表示两个区域有 overlap，则我们需要将后面一个区间移除。
                  # 因此 count += 1。因为是移除后面一个区间，所以 curr 此时不变
                  if intervals[i][0] < curr:
                      count += 1
                  # 没有 overlap，所以我们将 curr 移动到当前最大的区间的最右侧
                  else:
                      curr = intervals[i][1]
              return count
      ```
      
2. 

做题后：

1.  可以和 452. Minimum Number of Arrows to Burst Balloons 结合起来一起看

