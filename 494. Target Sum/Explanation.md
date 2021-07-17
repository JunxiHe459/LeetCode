# Target Sum

做题前：

1. 第一反应是递归，5分钟搞定直接 AC，结果  beat 5%。只好想想有没有其他的思路。

2. 想了想还是 DP 吧。

3. 将数组 nums 中的所有数，按 + 和 - 分为两类，设数组 m 含有所有 + 的数，数组 n 含有所有 - 的数。

   $$sum(m) - sum(n) = target$$

   $$sum(m) - sum(n) + sum(m) + sum(n) = target + sum(m) + sum(n) $$

   $$2 \times sum(m) = target + sum(nums)$$

   因此我们知道：

    	1. target + sum(nums) 必须是一个偶数
    	2. sum(m)，即 nums 中 所有 + 的数的和，等于 (target + sum(nums) ) / 2

4.  因此，问题被简化为，找到一个 nums 的 subset，使其中所有元素相加的和，等于  (target + sum(nums) ) / 2.



做题中：

1. 使用 DP 来解决上面的第 4 点。

2. 状态方程：dp[x] 表示，nums 一共有多少个 subset，其所有元素之和等于 x。

3. 初始化：dp[0] = 1，因为只有空集可以满足，所以为1。

4. 转移方程：$$dp[x] = \sum dp[a + b]$$,其中 a < dp.length(), b 属于 nums,  a + b == x

5. 返回值：dp[ target + sum(nums) ) / 2 ]

6. ```python
           dp = [0 for i in range(target + 1)]
           dp[0] = 1
           for i in nums:
               for j in range(target, i - 1, -1):
                   dp[j] += dp[j - i]
           return dp[target]
   ```

   从后往前更新，以免使用更新以后的值。

做题后：

1.  难点主要在 DP

