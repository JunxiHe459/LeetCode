class Solution:
    def numSquares(self, n: int) -> int:
        l = []
        i = 1
       	# 得到所有 <= n 的 perfect square
        while 1:
            sq = i ** 2
            i += 1
            if sq <= n:
                l.append(sq)
            else:
                break
        # BFS    
        stack = [n]
        count = 0
        while stack:
            count += 1
            temp = []
            for i in stack:
                for j in l:
                    num = i - j
                    if num == 0:
                        return count
                    if num < 0:
                        break
                    else:
                        temp.append(num)
            stack = temp
        return -1
            