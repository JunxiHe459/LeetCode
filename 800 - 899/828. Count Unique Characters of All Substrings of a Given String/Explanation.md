# 828. Count Unique Characters of All Substrings of a Given String

做题前：

1. Hard 难度的题，真的有点难
1. Brute Force 是 O(n^3)。首先找到一个 string 的所有 substring 是 O(n^2)，接着找到每一个 substring 里的 unique character 数量是 O(n)。所以总共是 O(n^2 * n ) = O(n^3)。
1. 不过这种 return 一个 int 的题目一般都可以简化，因为不关心每个 substring 具体长什么样子，只需要知道有多少个 unique character 就行了。

做题中：

1. 假设 ```curr(i``` 表示 s 中，所有以 ```s[i]``` 结尾的 substring 的 unique character 的 sum 
   
   1. 当 i = 0 时，```curr(i) = 1```
   1. ```curr(i + 1) = curr(i) + new_contribution(s[i])```
      1. ```new_contribution(s[i]) = i - last_position(s[i]) - old_contribution[s(i)]```
   
1. ```python
   class Solution:
       def uniqueLetterString(self, s: str) -> int:
           total = 0
           curr = 0
           last_position = [-1] * 256
           contribution = [0] * 256
           
           for i in range(len(s)):
               c = s[i]
               
               # Minus old contribution
               curr -= contribution[ord(c)]
               # Calculate new contribution
               contribution[ord(c)] = i - last_position[ord(c)]
               curr += contribution[ord(c)]
               
               # Record last_position
               last_position[ord(c)] = i
               
               total += curr
               
           return total
   ```



做题后：

1. 

