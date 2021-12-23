# 926. Flip String to Monotone Increasing

做题前：

1. 将一个二进制string 从小到大排列 ```0000....01...1111``` 关键点在于找到从 0 到 1 的那个点。我们就可以推出，需要翻多少次了。
1. 首先计算这个 string 里面有多少个 0，然后通过 len(s) - count_zero 得到有多少个 1。
1. 知道了有多少个 0，多少个 1 以后，我们就可以确定最大需要翻多少次了。
4. 于是我们遍历这个 string，通过需要翻多少个 0 + 需要翻多少个 1 来计算总共需要翻多少次，并找到这个值的最小值。
   1. 我们从左向右遍历，如果遇到 0，证明我们可以不用翻这个 0，于是 `count_zero -= 1`
   2. 如果遇到 1，证明我们需要将这个 1 变成 0，所以 `count_one += 1`
      1. 此时，需要翻的次数就是 `count_zero + count_one`


做题中：

1. ```python
   import sys
   class Solution:
       def minFlipsMonoIncr(self, s: str) -> int:
           count_zero = 0
           for i in s:
               if i == '0':
                   count_zero += 1
           
           result = len(s) - count_zero
           count_one = 0
           
           for i in s:
               if i == '0':
                   count_zero -= 1
               else:
                   result = min(count_zero + count_one, result)
                   count_one += 1
               
           return result
   ```

1. 



做题后：

1. 

