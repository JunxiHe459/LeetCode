# 203.  Remove Linked List Elements

做题前：

1. 



做题中：

1. Iteration:

   ```python
   # Definition for singly-linked list.
   # class ListNode:
   #     def __init__(self, val=0, next=None):
   #         self.val = val
   #         self.next = next
   class Solution:
       def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
           h = head
           prev = None
           curr = head
           while curr != None:
               if curr.val == val:
                   if prev == None:
                       curr = curr.next
                       h = curr
                   else:
                       prev.next = curr.next
                       curr = curr.next
               else:
                   prev = curr
                   curr = curr.next
           return h
   ```

2. Recursion:

   ```python
   # Definition for singly-linked list.
   # class ListNode:
   #     def __init__(self, val=0, next=None):
   #         self.val = val
   #         self.next = next
   class Solution:
       def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
           if head == None:
               return None
           if head.val == val:
               return self.removeElements(head.next, val)
           else:
               head.next = self.removeElements(head.next, val)
           return head
   ```

   



做题后：

1. 

