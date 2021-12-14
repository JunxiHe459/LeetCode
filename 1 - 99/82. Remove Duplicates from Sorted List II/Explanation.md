# 82. Remove Dups from Sorted List II

做题前：

1. 

做题中：

1. ```python
   class Solution:
       def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
           if not head:
               return None
           # 需要 Dummy Head，因为存在 head 有 duplicate 的情况
           dummy = ListNode()
           dummy.next = head
           prev = dummy
           temp = head
           count = 0
           
           while temp:
   			# 看看 temp 有没有 duplicate，如果有的话就移动到最后一个 duplicate 处
               while temp.next and temp.val == temp.next.val:
                   temp = temp.next
                   count += 1
               # 如果有 duplicate
               if count:
                   temp = temp.next
                   prev.next = temp
                   count = 0
               else:
                   prev = temp
                   temp = temp.next
           return dummy.next
   ```

1. 



做题后：

1. 

