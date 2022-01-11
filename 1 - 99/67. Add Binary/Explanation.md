# 67. Add Binary

做题前：

1. 



做题中：

1. ```python
   class Solution:
       def addBinary(self, a: str, b: str) -> str:
           total = self.binary_2_int(a) + self.binary_2_int(b)
           print(total)
           return bin(total)[2:]
       
       
       
       def binary_2_int(self, s: str) -> int:
           temp = 1
           total = 0
           for i in s[::-1]:
               if i == '1':
                   total += temp
               temp *= 2
           print(total)
           return total
   ```

1. 



做题后：

1. 

