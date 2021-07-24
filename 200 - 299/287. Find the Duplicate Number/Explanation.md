# Find the Duplicate Number

做题前：

1. 第一时间想到的是先排序，再二分查找。时间复杂度是 O(n log(n))。

2. 还可以用快慢指针的方式，与 142. Linked List Cycle II 是一模一样的。

3. 因为数组中的每一个 element 是 unique 的，只有一次重复，因此可以将数组看成有一个cycle 的 Linked List。

4. element 的值指向 next

   1. eg： [1, 4, 3, 2, 2] , slow: 1 -> 4-> 2-> 3-> 2-> 3-> 2-> 3..... Cycle detected.

      ​                                                          ^           ^            ^

      ​                    the second 2 in the array      the first 2 in the array



做题中：

1.  Cycle Detection：

   ```c++
           int fast = nums[nums[0]];
           int slow = nums[0];
           
           while(fast != slow)
           {
               fast = nums[nums[fast]];
               slow = nums[slow];
           }
   ```

2. Find the entrance of the cycle, which is the duplicate number in the array.

   ```c++
           int restart = 0;
           while(restart != slow)
           {
               slow = nums[slow];
               restart = nums[restart];
           }
   ```

3.  Why set ```slow = nums[0]``` but set ```restart = 0``` instead of ```nums[0]```? 

   1. 因为这里的 slow 和 fast 不是真正的 node，我们只能用他们的值来判断快慢指针是否碰到一起，所以不能让他们两个开始就一样。如果要是两个都从 0 开始，那么可以用 do while loop。
   2. slow = nums[0] 隐含着起点其实是在 0，第一步是 nums[0]，第二步是 nums[nums[0]]



做题后：

1. 

