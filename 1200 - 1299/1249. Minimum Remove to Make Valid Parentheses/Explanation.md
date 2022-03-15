# 1249. Minimum Remove to Make Valid Parentheses

做题前：

1. 看上去像是一道 Edit Distance 的题，但其实和 Edit Distance 没什么关系。这种需要 return 最后结果，而不是 minimum value 或者 maximum value 的题估计都和 DP 没什么关系其实。



做题中：

2. 

   ```python
   class Solution:
       def minRemoveToMakeValid(self, s: str) -> str:
           # 把 s 变成 list，提高效率
           l = list(s)
           stack = []
           for i in range(len(l)):
               if l[i] == '(':
                   stack.append(i)
               elif l[i] == ')':
                   # 如果前面有对应的 )，把上一个 ) pop 出去
                   if stack:
                       stack.pop()
                   # 如果没有，证明这个 ) 是必须去除的，直接改
                   else:
                       l[i] = ''
           # 然后把所有没有对应 ) 的 ( 给去除掉
           while stack:
               l[stack.pop()] = ''
           return ''.join(l)
   ```
   
   

做题后：

1. 

