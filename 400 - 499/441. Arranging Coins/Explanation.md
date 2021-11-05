# 441. Arranging Coins

做题前：

1. 

做题中：

1.  ```
       （首项 + 末项） * 项数 / 2
       ```

2. ```python
      class Solution:
          def arrangeCoins(self, n: int) -> int:
              i = 1
              while self.formula(i) + i < n: #当前是 i 行，如果要 n >= formula(i) + (i + 1) 才能至少把下一行填满
                  i += 1
              return i
          def formula(self, i) -> int:
              # （i + 1) 和 i 一定有一个是偶数
              return (1 + i) * i // 2
      ```

3. ```python
   # Binary Search is much better
   class Solution:
       def arrangeCoins(self, n: int) -> int:
           if n < 2:
               return n
           
           left = 0
           right = n - 1
           while left <= right:
               mid = left + (right - left) // 2
               curr = (1 + mid) * mid // 2
               
               if curr == n:
                   return mid
               elif n < curr:
                   right = mid - 1
               else:
                   left = mid + 1
           return right
           
   ```

4. 

做题后：

1.  

