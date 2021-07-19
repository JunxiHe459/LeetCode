class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = 0
        for i in nums:
            total += i
        if(total < target):
            return 0
        if( (target + total) % 2 == 1):
            return 0
        
        return self.dp(nums, (target + total) // 2)
    
    def dp(self, nums, target):
        dp = [0 for i in range(target + 1)]
        dp[0] = 1
        for i in nums:
            for j in range(target, i - 1, -1):
                dp[j] += dp[j - i]
        return dp[target]