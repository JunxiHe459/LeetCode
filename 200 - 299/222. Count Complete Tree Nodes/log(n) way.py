class Solution:
    def getHeight(self, root) -> int:
        if root == None:
            return -1
        else:
            return 1 + self.getHeight(root.left)
        
    def countNodes(self, root: Optional[TreeNode]) -> int:
        height = self.getHeight(root)
        if height == -1:
            return 0
        else:
            if self.getHeight(root.right) == height - 1:
                return 2 ** height + self.countNodes(root.right)
            else:
                return 2 ** (height - 1) + self.countNodes(root.left)