class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr = sys.maxsize
        dp = [0 for i in range(len(prices))]
        for i in range(len(dp)):
            if(curr > prices[i]):
                dp[i] = dp[i-1]
                curr = prices[i]
            else:
                dp[i] = dp[i-1] + prices[i] - curr
                curr = prices[i]
        return dp[-1]