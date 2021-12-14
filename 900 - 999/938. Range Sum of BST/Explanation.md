# 938.Range Sum of BST

做题前：

1. 递归就完事儿了
1. 注意 BST 的一些特性

做题中：

1. ```python
   class Solution:
       def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
           if not root:
               return 0
           
           if root.val < low:
               return self.rangeSumBST(root.right, low, high)
           
           if root.val > high:
               return self.rangeSumBST(root.left, low, high)
           
           return root.val + self.rangeSumBST(root.right, low, high) + self.rangeSumBST(root.left, low, high)
   ```

1. 



做题后：

1. 

