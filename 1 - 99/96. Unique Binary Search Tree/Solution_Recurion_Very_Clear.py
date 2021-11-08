class Solution:
    def numTrees(self, n: int) -> int:
        if n <= 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 5
        total = 0
        for i in range(1, n + 1):
            left = i - 1
            right = n - i
            total += self.numTrees(left) * self.numTrees(right)
        return total