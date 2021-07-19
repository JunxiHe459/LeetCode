# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if(root == None):
            return None
        
        s = []
        s.append(root)
        
        while(s):
            r = s.pop()
            
            temp = r.left
            r.left = r.right
            r.right = temp
            
            if(r.left != None): s.append(r.left)
            if(r.right != None): s.append(r.right)
        
        return root