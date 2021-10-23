class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        size = len(isConnected)
        parents = [i for i in range(size)]
        total = size
        for i in range(size):
            for j in range(i + 1, size):
                if isConnected[i][j]:
                    temp1 = self.findRoot(i, parents)
                    temp2 = self.findRoot(j, parents)
                    if temp1 != temp2:
                        parents[temp2] = temp1
                        total -= 1
        return total

        
        
    def findRoot(self, city: int, parents: List[int]):
        if city == parents[city]:
            return city
        else:
            return self.findRoot(parents[city], parents)