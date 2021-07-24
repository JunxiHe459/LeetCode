# Linked List Cycle II

做题前：

1. 题目要求我们找到一个存在 cycle 的 Linked List 中， 进入 cycle 的那一个 node，也就是 cycle 中的第一个 node。
2. 快慢指针
3. 数学推导



做题中：

1. 设从 List 的 head 到进入 cycle 的长度为 m，cycle 的长度为 n。快指针每次走 2 步 ``` fast = fast->next->next```，而慢指针每次走 1 步，``` slow = slow->next```。

2. 首先证明，如果有 cycle 存在，则快慢指针一定会相遇在 cycle 中的某一点。

   1. 在慢指针进入 cyccle 时，快指针一定已经在 cycle 中了
   2. 当快慢指针同时在 cycle 中时，则变成了追及问题。因为快指针的速度比慢指针的快，则快指针一定可以追及到慢指针。
   3. 因此当 ```slow == fast```，证明该 Linked List 存在一个 cycle。

3. 正如 2. 中所说，slow 和 fast 一定会相遇早 cycle 中的某一个点。==在证得 2. 后，我们设在相遇时，两个指针都已经走到了这个 cycle 中 y 个 node，还剩下 x 个 node 没有走，及 $x + y = n$。==

   1. 因此，我们可以知道，慢指针一共走了 m + y 步
   2. 因为快指针的速度为慢指针的两倍，因此快指针走了 2(m + y) 步，同时根据快指针的位置推断，快指针处于 m + kn + y 的位置，kn 意味着快指针在 cycle 中循环的圈数。因此，我们可以得到 2(m + y) = m + kn + y。化简得到 kn = m + y
   3. 将 y = n - x 代入 kn = m + y，我们得到 m + n - x = kn，因此 ==m = (k - 1)*n + x==
   4. m = (k - 1)*n + x 意味着当一个指针在 cycle 中 y 的指针出发，走 m 步之后，它会绕这个 cycle 走 k - 1 圈 + x 步。换句话说，从 y 出发，走 m 步后，这个指针最终会停在 x + y 的位置，也就是 cycle 的起点。
   5. 因此，我们让一个新的指针从起点出发，当它和从 y 出发的指针相碰时，所在的位置就是这个 cycle 的起点。

4. 上代码：

   1. 先确定有 cycle（快慢指针走到 y 的位置）

      ```c++
              while(slow && fast && fast->next)
              {
                  slow = slow->next;
                  fast = fast->next->next;
                  if(slow == fast)
                  {
                      break;
                  }
              }
              // 判断是否有 cycle
              if(fast == NULL || fast->next == NULL)
              {
                  return NULL;
              }
      ```

      

   2. 然后让一个新指针从起点出发，去和从 y 出发的指针会和。

      ```c++
              else
              {
                  ListNode* temp = head;
                  while(temp != fast)
                  {
                      temp = temp->next;
                      fast = fast->next;
                  }
                  return temp;
              }
      ```

      



做题后：

1. 数学推导可能第一次见不容易想出来，但是==快慢指针==的想法真的挺经典的
2. 这个题在很久之前就做了，最近来温故看看能否知新。

