# 696. Count Binary Substrings

做题前：

1. First, I count the number of 1 or 0 grouped consecutively.
   For example "0110001111" will be `[1, 2, 3, 4]`.

   

   Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring will be the minimum number of 0 and 1.
   For example "0001111", will be `min(3, 4) = 3`, (`"01", "0011", "000111"`)



做题中：

1. ```python
   class Solution:
       def countBinarySubstrings(self, s: str) -> int:
           pre = 0
           now = 0
           curr = s[0]
           total = 0
           for i in s:
               if i == curr:
                   now += 1
               else:
                   total += min(now, pre)
                   pre = now
                   now = 1
                   curr = i
                   
           return total + min(now, pre)
   ```

1. 



做题后：

1. 

