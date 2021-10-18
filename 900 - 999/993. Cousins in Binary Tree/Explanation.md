# 993. Cousins in Binary Tree

做题前：

1. 

做题中：

1. ```python
       def search(self, root, val, parent, level):
           if root != None:
               if root.val == val:
                   return parent, level
               else:
                   return self.search(root.left, val, root, level + 1) or 										self.search(root.right, val, root, level+1)
           else:
               return None
   ```

2. 注意第 6 行这个条件，None 也可以作为 bool 值来判断



做题后：

1. 

