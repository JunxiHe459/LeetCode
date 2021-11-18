# 62. Unique Paths

做题前：

1. 




做题中：

1. 巨慢 Recursion
       
       ```python
       class Solution:
           def uniquePaths(self, m: int, n: int) -> int:
               return self.myUniquePaths(1, 1, m, n)
           def myUniquePaths(self, i, j, m, n):
               if i > m or j > n:
                   return 0
           if i == m and n == j:
                 return 1
             return self.myUniquePaths(i + 1, j, m, n) + self.myUniquePaths(i, j + 1, m, n)
     ```
     
1. 当然要 DP 啦
       
       ```python
       class Solution:
           def uniquePaths(self, m: int, n: int) -> int:
               dp = [[0 for i in range(n)] for j in range(m)]
               for i in range(m):
                   dp[i][0] = 1
               for i in range(n):
               dp[0][i] = 1
             for i in range(1, m):
                 for j in range(1, n):
                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
             return dp[-1][-1]
     ```
     
   

   

   

做题后：

1. 

   

   


