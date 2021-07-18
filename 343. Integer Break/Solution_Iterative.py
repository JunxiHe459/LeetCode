class Solution:
    def integerBreak(self, n: int) -> int:
        
        if(n == 2):
            return 1
        if(n == 3):
            return 2
        total = 1
        
        while(n > 1):
            if(n > 4 or n == 3):
                total *= 3
                n -= 3
                continue
            if(n == 4 or n == 2):
                total *= 2
                n -= 2
                continue
        return total