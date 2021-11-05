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

做题后：

1.  

