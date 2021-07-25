import sys
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr = sys.maxsize
        dp = [0 for i in range(len(prices))]
        for i in range(len(dp)):
            if curr > prices[i]:
                curr = prices[i]
            profit = prices[i] - curr
            dp[i] = max(dp[i-1], profit)
        return dp[-1]