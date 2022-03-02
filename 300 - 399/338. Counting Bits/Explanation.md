# 338. Counting Bits

做题前：

1. 用 DP，对于一个数 N 的二进制来说，它有几个 bit 为 1 呢？

   假设 f(x) = how many bits x has that is 1

   `f(x) = f(x/2) + 1 if x is odd`

   `f(x) = f(x/2) if x is even`

做题中：

1. ```python
   class Solution:
       def countBits(self, n: int) -> List[int]:
           # result = [0] * (n + 1)
           result = [0 for i in range(n+1)]
           for i in range(1, n + 1):
               result[i] = result[i // 2] + i % 2
               # i // 2 == i >> 1
               # i % 2 == i & 1
               # 不过无所谓了，编译器都会优化的
           return result
   ```

做题后：

1. 

