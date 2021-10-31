# 430. Flatten a Multilevel Doubly Linked List

做题前：

1. 感觉很简单啊，就是一个排序题。遇到有 child 的就插队就完事儿了

做题中：

1. Naive Way （缺点在于 Space Complexity)

      ```python
      """
      # Definition for a Node.
      class Node:
          def __init__(self, val, prev, next, child):
              self.val = val
              self.prev = prev
              self.next = next
              self.child = child
      """
      
      class Solution:
          def flatten(self, head: 'Node') -> 'Node':
              if not head:
                  return None
              stack = [head]
              arr = []
              
              # Get the right order
              while stack:
                  curr = stack.pop(0)
                  arr.append(curr.val)
                  if curr.next:
                      stack = [curr.next] + stack
                  if curr.child:
                      stack = [curr.child] + stack
                      
              # Construct the result doubly linked list      
              dummy = Node()
              curr = dummy
              for i in arr:
                  n = Node(i)
                  n.prev = curr
                  curr.next = n
                  curr = n
              dummy.next.prev = None
              return dummy.next
                  
      ```

2. Naive Way 还可以做的更好：

      ```python
      class Solution:
          def flatten(self, head: 'Node') -> 'Node':
              if not head:
                  return None
              stack = [head]
              arr = []
              
              dummy = Node()
              h = dummy
              # Get the right order
              # 直接在 Sort 的时候把 Doubly Lined List 建好
              while stack:
                  curr = stack.pop(0)
                  if curr.next:
                      stack = [curr.next] + stack
                      curr.next = None
                  if curr.child:
                      stack = [curr.child] + stack
                      curr.child = None
                  curr.prev = h
                  h.next = curr
                  h = h.next
              dummy.next.prev = None
              return dummy.next
      ```

      

3. 

做题后：

1.  

