# 404. Sum of Left Leaves

做题前：

1. Easy

做题中：

1. 

      ```python
      # Definition for a binary tree node.
      # class TreeNode:
      #     def __init__(self, val=0, left=None, right=None):
      #         self.val = val
      #         self.left = left
      #         self.right = right
      class Solution:
          def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
              return self.LeftLeaf(root, 0)
          def LeftLeaf(self, root, left) -> int:
              if root == None:
                  return 0
              if root.left == None and root.right == None:
                  if left:
                      return root.val
                  else:
                      return 0
              return self.LeftLeaf(root.left, 1) + self.LeftLeaf(root.right, 0)    
      ```
      

做题后：

1.  

