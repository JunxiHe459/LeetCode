# 234. Palindrome Linked List

做题前：

1. 做出来很简单，但怎么做到 O(1) 的 sapce comlexity 很难
1. 涉及到链表前后两个部分的情况，多想想快慢指针

做题中：

1. O(n) time + O(n) space, recursion

   ```python
   temp = None
   
   class Solution:
       def isPalindrome(self, head: Optional[ListNode]) -> bool:
           global temp
           temp = head
           return self.check(head)
       
       def check(self, head: Optional[ListNode]) -> bool:
           global temp
           if not head:
               return True
           flag = self.check(head.next) and head.val == temp.val
           temp = temp.next
           return flag
   ```

2. O(n) time + O(1) space, reverse the first half of the linked list

   ```python
   class Solution:
       def isPalindrome(self, head: Optional[ListNode]) -> bool:
           rev = None
           slow = head
           fast = head
           
           while fast and fast.next:
               fast = fast.next.next
               n = slow.next
               slow.next = rev
               rev = slow
               slow = n
           
           # This situation happens when the linked list
           # has odd number of nodes
           if fast:
               slow = slow.next
           
           # Compare the reversed first half with the second half, which started with slow
           while rev and rev.val == slow.val:
               rev = rev.next
               slow = slow.next
           return not rev
   ```

3. Go Implementation

   ```go
   func isPalindrome(head *ListNode) bool {
       fast := head
       slow := head
       var rev *ListNode
       
       for fast != nil && fast.Next != nil {
           fast = fast.Next.Next
           
           next := slow.Next
           slow.Next = rev
           rev = slow
           slow = next
       }
       
       // If the linked list has odd number of nodes
       if fast != nil {
           slow = slow.Next
       }
       
       for rev != nil && rev.Val == slow.Val {
           rev = rev.Next
           slow = slow.Next
       }
       
       return rev == nil
   }
   ```

   

做题后：

1. 

