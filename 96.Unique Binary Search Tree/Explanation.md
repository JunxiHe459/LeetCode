# Unique Binary Search Tree

做题前：

1. Backtracking？
2. Recursion？
3. DP？



做题中：

1. ==dp[i] += dp[j] * dp[i - j - 1] 是因为当以 i 为 root 的时候，一共会有 i 种不同的情况，==

   ​	分别是：

   ​		左边                  右边

   ​		   0                     i - 1

   ​		   1                     i - 2

   ​		   2                     i - 3

   ​		   i                        0



做题后：

1. 为什么没有第一时间想到用 DP 来做这个题？
2. DP 四大要点：
   1. 状态方程 State： [i] 表示第一个包含从[1, i]个节点的二叉树有多少种不同的画法
   2. 初始值 Init：[0] = 1，[1] = 1
   3. 转移方程 Function：$dp[i] = \sum{dp[j] \times d[i - j - 1]}$
   4. 结果 Result：dp[n]
3. 参考：https://www.youtube.com/watch?v=GZ0qvkTAjmw





关于Solution_Recursion:

 	1. 利用map来实现
 	2. ==sum += count(i - 1, m) * count(n - i, m);==
