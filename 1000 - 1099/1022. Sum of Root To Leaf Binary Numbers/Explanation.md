# 1022. Sum of Root To Leaf Binary Numbers

做题前：

1. 



做题中：

1.  DFS 然后 再把字符串转成 int

   ```python
   class Solution:
       def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
           return self.DFS(root, "")
       
       
       def DFS(self, root, curr) -> int:
           if not root.left and not root.right:
               return int(curr + str(root.val), 2)
           else:
               l, r = 0, 0
               if root.left:
                   l = self.DFS(root.left, curr + str(root.val))
               if root.right:
                   r = self.DFS(root.right, curr + str(root.val))
               return l + r
   ```

2. 

   



做题后：

1. 

