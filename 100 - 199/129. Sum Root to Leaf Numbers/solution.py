# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        arr = self.DFS(root, "")
        total = 0
        for i in arr:
           total += int(i) 
        return total

    def DFS(self, root, curr) -> [str]:
        curr +=  str(root.val)
        if root.left == None and root.right == None:
            return [curr]
        arr = []
        if root.left != None:
            arr += self.DFS(root.left, curr)
        if root.right != None:
            arr += self.DFS(root.right, curr)
        return arr