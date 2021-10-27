# 279. Perfect Square

做题前：

1. DFS  最慢最辣鸡

2. BFS  好像还阔以

   ![image-20211027201952233](/Users/junxihe/Desktop/LeetCode/200 - 299/279. Perfect Square/image-20211027201952233.png)

3. DP


做题中：

1. BFS 的做法

   ```python
   class Solution:
       def numSquares(self, n: int) -> int:
           l = []
           i = 1
          	# 得到所有 <= n 的 perfect square
           while 1:
               sq = i ** 2
               i += 1
               if sq <= n:
                   l.append(sq)
               else:
                   break
           # BFS    
           stack = [n]
           count = 0
           while stack:
               count += 1
               temp = []
               for i in stack:
                   for j in l:
                       num = i - j
                       if num == 0:
                           return count
                       if num < 0:
                           break
                       else:
                           temp.append(num)
               stack = temp
           return -1
               
   ```

   

2. DP 的做法

   ```python
   class Solution:
       def numSquares(self, n: int) -> int:
           dp = [0 for i in range(n + 1)]
           for i in range(1, len(dp)a):
               temp = 1
               m = sys.maxsize
               while temp ** 2 <= i:
                   m = min(m, dp[i - temp ** 2] + 1)
                   temp += 1
               dp[i] = m
           return dp[-1]
   ```

3. 

做题后：

1. 

