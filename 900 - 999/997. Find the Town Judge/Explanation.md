# 997. Find the Town Judge

做题前：

1. Single Array
1. 找到 `count[i] == N - 1` 是关键

做题中：

1. ```python
   class Solution:
       def findJudge(self, N, trust):
           count = [0] * (N + 1)
           for i, j in trust:
               count[i] -= 1
               count[j] += 1
           for i in range(1, N + 1):
               if count[i] == N - 1:
                   return i
           return -1
   ```
   
1. 



做题后：

1. 

