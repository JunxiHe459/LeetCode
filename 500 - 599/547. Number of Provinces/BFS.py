class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        province = 0
        visited = [0 for i in range(len(isConnected))]
        for i in range(len(isConnected)):
            if visited[i] != 0:
                continue
            visited[i] = 1
            province += 1
            stack = [i]
            while stack:
                city = stack.pop(0)
                for j in range(len(isConnected[city])):
                    if isConnected[city][j] and not visited[j]:
                        visited[j] = 1
                        stack.append(j)
        return province