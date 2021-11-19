# 461. Hamming Distance

做题前：

1. Easy

做题中：

1. ```python
      class Solution:
          def hammingDistance(self, x: int, y: int) -> int:
              total = 0
              while x or y:
                  temp_x = x >> 1
                  temp_y = y >> 1
                  total += (x - temp_x * 2 != y - temp_y * 2)
                  x = temp_x
                  y = temp_y
              return total
      ```

2. ```python
   class Solution:
       def hammingDistance(self, x: int, y: int) -> int:
           total = 0
           result = x ^ y
           while result:
               temp = result >> 1
               total += result  - temp * 2
               result = temp
           return total
   ```

做题后：

1.  

