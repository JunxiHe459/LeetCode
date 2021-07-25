# Best Time to Buy and Sell Stock

做题前：

1. 经典DP
2. Best Time to Buy and Sell Stock 系列入门



做题中：

1. 状态方程：dp[i] = 到 i 天为止的 max profit 是多少
2. 初始化：```dp = [0 for i in range(len(prices))]```
3. 需要一个额外的变量来记录 i 天前，股票价格的最低值，记为 curr，初始化 ```curr = sys.maxsize```。
4. 转移方程：```dp[i] = max(dp[i - 1], prices[i] - curr)```。
   1. ```dp[i - 1] ```指到 i - 1天为止的 max profit
   2. ```prices[i] - curr ```指如果在第 i 天卖出的 max profit
   3. 谁大就选谁
5. 最终结果：```dp[-1]```



做题后：

1. 一维数组的 DP 其实都不算难，只要思路按照以上 4 个步骤一步一步的去思考，就很容易找到正确的思路。

