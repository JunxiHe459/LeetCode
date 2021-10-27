class Solution:
    def numSquares(self, n: int) -> int:
        l = []
        i = 1
        while 1:
            sq = i ** 2
            i += 1
            if sq <= n:
                l.append(sq)
            else:
                break
        return self.BFS(n, l)
    
    def BFS(self, n, arr) -> int:
        if n < 0:
            return sys.maxsize
        if n <= 1:
            return n
        result = []
        for i in arr:
            result.append(1 + self.BFS(n - i, arr))
        return min(result)