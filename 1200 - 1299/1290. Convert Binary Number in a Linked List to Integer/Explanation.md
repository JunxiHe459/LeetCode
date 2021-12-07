# 1290. Convert Binary Number in a Linked List to Integer

做题前：

1. 



做题中：

1. ```python
   # Definition for singly-linked list.
   # class ListNode:
   #     def __init__(self, val=0, next=None):
   #         self.val = val
   #         self.next = next
   class Solution:
       def getDecimalValue(self, head: ListNode) -> int:
           result = 0
           while head:
               result += head.val
               result = result << 1
               head = head.next
           return result >> 1
   ```



做题后：

1. 

