## 题目

给一串数组 ```[a,b,c,d]```，给一个 maxCapacity，找到一个 subarray 使其所有元素相加的和最大但不超过 maxCapacity。

## 想法

1. 看到题目瞬间就想到 Knapsack, 肯定是要 DP 来做的。（结果搞忘了 : / )
2. DP 解法见 Solution.cpp

```c++
                // If the item we are going to put is not big enough to outweight the maxCapacity
                if(arr[idx] <= maxCapacity)
                {
                    // This line is the key of the DP
                    // It says that if the dp[i][j] should be the max of 2 possiblities
                    // 1.
                    // dp[i - 1][j - arr[i - 1]] means that we take the i-th item in the arr,
                    // so now the total value is the max value of the value of i-th item +
                    // selcting from 1-th to (i-1)-th item in the arr with maxCpacity at maxCapacity - the value of i-th item
                    // 2.
                    // the max value can be dp[i - 1][j] which means that selcting 
                    // from 1-th to (i-1)-th item in the arr with maxCpacity not changed.
                    dp[i][j] = max(dp[idx - 1][j - arr[idx]] + arr[idx], dp[idx - 1][j]);
                }
```

