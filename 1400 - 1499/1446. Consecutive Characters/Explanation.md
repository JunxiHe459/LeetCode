# 1446. Consecutive Characters

做题前：

1. 



做题中：

1. ```python
   class Solution:
       def maxPower(self, s: str) -> int:
           # 需要判断一下，尽管没有这些 testcase
           if not s or len(s) == 0:
               return 0
           
           curr = s[0]
           result = 0
           count = 1
           for i in range(1, len(s)):
               if s[i] == curr:
                   count += 1
               else:
                   result = max(result, count)
                   count = 1
                   curr = s[i]
           return max(result, count)
   ```

1. 



做题后：

1. 

