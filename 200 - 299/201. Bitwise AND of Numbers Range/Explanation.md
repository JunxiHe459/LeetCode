# 201. Bitwise AND of Numbers Range

做题前：

1. **==This problem is asking us to find the common prefix of m and n 's binary code.==**

   

做题中：

1.  ```python
    class Solution:
        def rangeBitwiseAnd(self, m: int, n: int) -> int:
            # very important
            # Assume m has x digits and n has y digits, y > x
            # If the lenght of the binary string of m and n are not the same
            # Meaning that:
            # 1. digits from position [x + 1, y] is absolutely 0
            # 2. digits from position [0, x] will be zero because there will be a time
            # when the number is 10000000000 where the only 1 is at the y-th position
            # and other position are all zeros.
            if len(bin(m)) != len(bin(n)): return 0
            
            # Slow loop
            for i in range(m+1, n+1):
                m = m & i
            return m
    ```

2. 以上还不是最快的做法，还有一种更变态的

   ```python
   class Solution:
       def rangeBitwiseAnd(self, m: int, n: int) -> int:
           # very important
           # Assume m has x digits and n has y digits, y > x
           # If the lenght of the binary string of m and n are not the same
           # Meaning that:
           # 1. digits from position [x + 1, y] is absolutely 0
           # 2. digits from position [0, x] will be zero because there will be a time
           # when the number is 10000000000 where the only 1 is at the y-th position
           # and other position are all zeros.
           if len(bin(m)) != len(bin(n)): return 0
               
           # Fast Loop
           # As what I said in part 1:
           # "This problem is asking us to find the common 
           #  prefix of m and n 's binary code."
           factor = 1
           while m != n:
               m >>= 1
               n >>= 1
               factor <<= 1
           return m * factor
   ```

3. string 操作的做法：

   思路是一样的，string 更方便理解

   ```python
           bin_m = bin(m)
           bin_n = bin(n)
           if len(bin(m)) != len(bin(n)): return 0
           flag = True
           s = ""
           for i in range(0, len(bin_m)):
               if not flag:
                   s += "0"
               else:
                   flag = (bin_m[i] == bin_n[i])
                   s += bin_m[i]
           return int(s, 2)
   ```

   

做题后：

1. 

