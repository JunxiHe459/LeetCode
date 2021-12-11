# 61. Rotate List

做题前：

1.  假设有 linked list  `1 -> 2 -> 3 -> 4 -> 5` `k = 2`
1. 最终结果就是 `4 -> 5 -> 1 -> 2 -> 3`
3. 从结果来看，我们就是要做两件事情：
   1. 把 5 和 1 中间的 `->` 加上
   2. 把 3 和 4 中间的 `->` 减去


做题中：

1. ```go
   /**
    * Definition for singly-linked list.
    * type ListNode struct {
    *     Val int
    *     Next *ListNode
    * }
    */
   func rotateRight(head *ListNode, k int) *ListNode {
       if head == nil {
           return nil
       }
       
       length := 1
       temp := head
       for temp.Next != nil {
           temp = temp.Next
           length++
       }
       
       // Craete a loop linked list
       // 等于上面的 1. 把 5 和 1 中间的 `->` 加上
       temp.Next = head
       
       
       for moves := length - (k % length); moves > 0; moves-- {
           temp = temp.Next
       }
       
       head = temp.Next
       // 等于上面的 2. 把 3 和 4 中间的 `->` 减去
       temp.Next = nil
       
       return head
   }
   ```

做题后：

1. 

