class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        dp = [(1, i) for i in range(len(nums))]
        for i in range(len(nums)):
            curr = nums[i]
            inc = dp[i][0]
            for j in range(i + 1, len(nums)):
                if nums[j] % curr == 0 and inc + 1 > dp[j][0]:
                            dp[j] = (inc + 1, i)
                        
        idx = -1
        max_ = -1
        for i in range(len(dp)):
            if dp[i][0] > max_:
                max_ = dp[i][0]
                idx = i
                
        result = []
        while idx != dp[idx][1]:
            result.append(nums[idx])
            idx = dp[idx][1]
        result.append(nums[idx])
        return result
                