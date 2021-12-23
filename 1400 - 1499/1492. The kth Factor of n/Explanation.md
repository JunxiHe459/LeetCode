# 1492. The kth Factor of n

做题前：

1. 遍历 1 到 sqrt(n) 去找到 n 的所有因数

做题中：

1. ```python
   import math
   class Solution:
       def kthFactor(self, n: int, k: int) -> int:
           left = []
           right = []
           
           for i in range(1, int(math.sqrt(n)) + 1):
               print(i)
               if n % i == 0:
                   left.append(i)
                   right.append(n // i)
               
           if left[-1] == right[-1]:
               del right[-1]
           result = left + right[::-1]
           
           return -1 if len(result) < k else result[k - 1]
   ```

做题后：

1. 

