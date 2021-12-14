# 83. Remove Duplicates from Sorted List

做题前：

1. 



做题中：

1. ```python
   class Solution:
       def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
           if not head:
               return None
           
           prev = head
           temp = head.next
           while temp:
               if temp.val == prev.val:
                   temp = temp.next
                   prev.next = temp
               else:
                   prev = temp
                   temp = temp.next
           return head
   ```

1. 



做题后：

1. 

