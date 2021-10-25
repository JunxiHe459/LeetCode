# 222. Count Complete Tree Nodes

做题前：

1. **==这道题 tricky 的地方在于，它是一个 complete binary tree==**
   1. 什么是 complete binary tree ？
      1. 就是除了最后一层外，每一层都是满的。
      2. 最后一层所有的节点都是从左开始
   2. 如图所示<img src="/Users/junxihe/Desktop/LeetCode/200 - 299/222. Count Complete Tree Nodes/image-20211024193743958.png" alt="image-20211024193743958" style="zoom:25%;" />
   3. **==一个 complete binary tree 拥有==  **$2^{height + 1} - 1$  **==个 nodes==**
   4. root 的 height 是 0  ==> 2^(0 + 1) - 1 = 1

做题中：

1. log(N) way

   ```python
   class Solution:
       # 因为是一个 complete bnary tree，所以一直往左即可知道高度
       def getHeight(self, root) -> int:
           if root == None:
               return -1
           else:
               return 1 + self.getHeight(root.left)
           
       def countNodes(self, root: Optional[TreeNode]) -> int:
           height = self.getHeight(root)
           # 如果高度为 -1，证明是 None，return 0
           if height == -1:
               return 0
           else:
               # ！！！ 一个 complete binary tree 拥有 2^(height + 1) - 1 个 node
               # 因为是 complete binary tree，getHeight(root.left) == getHeight(root) - 1
               # 这里判断实际上是在判断 root 的左右两个分支高度是否相等
               if self.getHeight(root.right) == height - 1:
                   # 如果左右高度相等，证明左边是满的，高度为 height 
                   # 所以是 2 ** height + 右边有多少 nodes
                   return 2 ** height + self.countNodes(root.right)
               else:
                   # 如果右边高度比左边小，证明右边是满的，但是高度为 height - 1
                   # 所以是 2 ** (height - 1) + 左边有多少 nodes
                   return 2 ** (height - 1) + self.countNodes(root.left)
   ```

   

2. Naive way:

   ```python
   class Solution:
       def countNodes(self, root: Optional[TreeNode]) -> int:
           if not root:
               return 0
           else:
               return 1 + self.countNodes(root.left) + self.countNodes(root.right)
   ```

3. Naive way 2:

   ```python
       def countNodes(self, root: Optional[TreeNode]) -> int:
           count = 0
           if root:
               stack = [root]
               while stack:
                   curr = stack.pop(0)
                   count += 1
                   if curr.left:
                       stack.append(curr.left)
                   if curr.right:
                       stack.append(curr.right)
           return count
   ```

4. 

做题后：

1. 

