## Best Time to Buy and Sell Stock with Cooldown

做题前：

1.  DP
2. 只用一个数组，是很难解出来的。
3. ==题目分析==：
   1. 每一次我们有 3 种选择，买入，卖出，啥也不干
   2. ==两大规则==：卖出之前必须买入，卖出后的下一天必定啥也不干
   3. 设 ```buy[n], sell[n], rest[n] ```三个数组
   4. ```buy[i], sell[i], rest[i]```分别表示第 i + 1 天（ i 从 0 开始）的操作为 buy，sell，rest 时，当前赚取的利润。==注意：当前赚取的利润可以为负，也可以减少(因为买入)。==
   5. 于是我们可以根据==两大规则==推导出：
      1. ```buy[i] = max(rest[i - 1] - prices[i], buy[i - 1])```，从“这轮买入后当前利润”和“上轮买入后当前的例如”中取最大值。简单的理解就是如果发现当前轮买入的价格，```prices[i]```比上一轮的低，则会取```rest[i - 1] - prices[i]```，否则就延续上一轮的买入价格```buy[i - 1]```
      2. ```sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])```从“这轮卖出后当前利润”和“上轮卖出后当前的例如”中取最大值。
      3. ```rest[i] = max(sell[i - 1], rest[i - 1])```从卖出和啥也不干中取最大值。为什么没```buy[i - 1]```呢，因为```buy[i] = max(rest[i - 1] - prices[i], buy[i - 1])```意味着 ```buy[i]  <= rest[i - 1]```



做题中：

1. 我们直接从第二天开始，因为第一天的值可以直接推导。

   ```c++
           buy[0] = -prices[0];
           
           for(int i = 1; i < size; i++)
           {
               buy[i] = max( rest[i - 1] - prices[i], buy[i - 1]);
               sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
               rest[i] = max(sell[i - 1], rest[i - 1]);
           }
   
   		return max(rest[size - 1], sell[size - 1]);
   ```

   ```sell[0] = 0``` 因为第 1 天时还未买入任何股票。

   ```rest[0] = 0```因为如果第 1 天啥也不做，则当前利润一定为 0。

2. 根据 ```buy, sell, rest```三者之间的关系，我们其实可以进一步的推导出：

   1.  ```sell[i - 1] >= rest[i - 1]```因为卖出得到的收益 (>= 0)  一定 >= 啥也不干的收益 (0)，所以我们可以得到：```rest[i] = sell[i - 1]```。
   2. 将```rest[i] = sell[i - 1]```代入```buy[i] = max( rest[i - 1] - prices[i], buy[i - 1])```，我们可以得到：```buy[i] = max( sell[i - 2] - prices[i], buy[i - 1])```
   3. 因此简化为：```buy[i] = max(sell[i-2]-price, buy[i-1])``` 和 ```sell[i] = max(buy[i-1]+price, sell[i-1])```

3. ```c++
           int prev_buy;
           int buy = -prices[0];
           int sell = 0;
           int prev_sell = 0;
           
           for(int i = 1; i < prices.size(); i++)
           {
               // 将 prev_buy 赋值为 buy[i-1]
               prev_buy = buy;
               // 此时，prev_buy = buy[i - 1], *** prev_sell = sell[i - 2] ***
               buy = max(prev_sell - prices[i], prev_buy);
               
               // 将 prev_sell 赋值为 sell[i-1]
               prev_sell = sell;
               //此时，prev_buy = buy[i - 1], *** prev_sell = sell[i - 1] ***
               sell = max(prev_buy + prices[i], prev_sell);
           }
   ```

   



做题后：

1. 当一个 dp  很难表示多种选择时，是不是可以尝试用多个 dp 来表示状态呢？

