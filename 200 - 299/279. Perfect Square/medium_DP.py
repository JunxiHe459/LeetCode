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