# 1167. Minimum Cost to Connect Sticks

做题前：

1. 



做题中：

1. 很慢的做法，主要是看一下 bisect 怎么用

   ```python
   class Solution:
       def connectSticks(self, sticks: List[int]) -> int:
           sticks.sort()
           total = 0
           while len(sticks) != 1:
               a = sticks.pop(0)
               b = sticks.pop(0)
               bisect.insort_left(sticks, a + b)
               total += a + b
           return total
   ```

   `bisect.insort_left(arr, value)` 在已经 sort 的arr 里面插入一个 value，使 arr 仍然被 sort

2. 用 min heap

   ```python
   class Solution:
       def connectSticks(self, sticks: List[int]) -> int:
           heapify(sticks)
           total = 0
           while len(sticks) != 1:
               value = heappop(sticks) + heappop(sticks)
               total += value
               heappush(sticks, value)
           return total
   ```

做题后：

1. 

