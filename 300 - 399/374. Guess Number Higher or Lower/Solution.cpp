class Solution:
    def guessNumber(self, n: int) -> int:
        left = 1
        right = n
        while left < right:
            mid = int( (left + right) / 2)
            result = guess(mid)
            if result == 0:
                return mid
            if result < 0:
                right = mid - 1
            if result > 0:
                left = mid + 1
        return left