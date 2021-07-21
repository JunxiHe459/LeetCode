# Odd Even Linked List

做题前：

1. 就用两个指针分别指代当前单数 node 和 双数 node 所在的位置，最后再将最后一个单数 node 的 next 设为 双数 node 的开始。



做题中：

1. 一开始想的是一个一个加，先判断当前增加的是单数位置的还是双数位置，再加到对应的位置。

2. 后来发现了一种更聪明的解法。无论是单数还是双数，要添加的都是 current.next.next，用一个while loop 一直添加就好了。

   ```java
       while (CONDITION) {
         odd_curr.next = odd_curr.next.next;
         odd_curr = odd_curr.next;
   
         even_curr.next = even_curr.next.next;
         even_curr = even_curr.next;
       }
   ```

3. 关键点在于，while 循环中的条件应该是什么呢？

   因为是从 odd 开始的， odd even odd even odd even 的顺序，那么每一次循环的最后一个 node 一定是 even。

   如果在一个循环结束后， even 已是 null，证明我们已经超过了 list 一位，break。

   如果在一个循环结束后，even 不是 null，但 even 的下一位是 null，证明 even 正好处于 list的末端，break。

做题后：

1. 关于 linkedlist 的题目，一定要强迫自己去思考 O(1) Space Complexity 的解法。

