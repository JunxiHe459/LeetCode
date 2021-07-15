# Recover Binary Search Tree

做题前：

1. 因为只有2个 node 有问题，直接找到这两个 node 就行了

2. 对于一个Binary Search Tree而言，他的 in-order traversal 必须是从小到大排列的，如果存在prev > curr 的情况， 第一个 prev 和 第二个 curr 是有问题的node。

   eg：

   ```java
   root = [1,3,null,null,2]
   ```

   in order：3 2 1

   第一次 prev > curr : 3 > 2, 所以 3 有问题

   第二次 prev > curr : 2 > 1, 所以 1 有问题

   交换 3 和 1 之后：1 2 3， OK！



做题中：

1. ```java
           if(firstElement == null)
           {
               if(root.val < prev.val)
               {
                   firstElement = prev;
               }
           }
           // 必须用 if(firstElement != null)作为条件，
   		// 而不能直接else
           if(firstElement != null)
           {
               if(root.val < prev.val)
               {
                   secondElement = root;
              
   ```

   这里不能直接写 else 的原因是可能存在

   ```java
   root = [3,1,4,null,null,2]
   ```

    in-order 为 1, 3, 2 ,4的情况, 全程只有一次 root.val < prev.val 的情况， 必须一次性把firstElement 和 secondElement 都完成赋值。

   

做题后：

1. Binary Search Tree 的特性一定要熟悉

   目前想到的有：

   1. Assume root.val = k

      左边的为 [min, k - 1]

      右边的为 [k + 1, max]

   2. In-order traverse 一个 Binary Search Tree，出来的结果一定是从小到大排列的。

2. 了解一下 Morris Traversal

   

   

   

   

   

