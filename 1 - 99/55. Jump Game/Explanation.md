# 55. Jump Game

做题前：

1. Dynamic Programming

   

做题中：

1. ```python
   class Solution:
       def canJump(self, nums: List[int]) -> bool:
           last = len(nums) - 1
           for i in range(len(nums) - 2, -1, -1):
               if i + nums[i] >= last:
                   last = i
           return last <= 0
   ```

2. 要想跳到第 last 格，则 n 前面的某一个必须满足 i + nums[i]  >=  last

3. 如果满足以上条件，我们让 last 移动到 i 的位置，继续循环判断是否可以从某一位跳到 last

4. 如果 last = 0，则证明从起点 0 出发可以跳到终点，True

5. 否则 return false



做题后：

1. 

