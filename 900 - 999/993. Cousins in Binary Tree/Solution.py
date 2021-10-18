class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        x_parent, x_level = self.search(root, x, None, 0)
        y_parent, y_level = self.search(root, y, None, 0)
        return x_level == y_level and x_parent != y_parent
    
    def search(self, root, val, parent, level):
        if root != None:
            if root.val == val:
                return parent, level
            else:
                return self.search(root.left, val, root, level + 1) or self.search(root.right, val, root, level+1)
        else:
            return None
                