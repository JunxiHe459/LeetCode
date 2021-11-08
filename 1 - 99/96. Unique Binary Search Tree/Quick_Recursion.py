class Solution:
    def numTrees(self, n: int) -> int:
        m = {0:1, 1:1, 2:2}
        return self.count(n, m)
    def count(self, n: int, m) -> int:
        
        if n in m:
            return m[n]
        
        total = 0
        for i in range(1, n + 1):
            total += self.count(i - 1, m) * self.count(n - i, m)
        m[n] = total
        return total