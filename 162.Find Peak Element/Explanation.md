# Find Peak Element

做题前：

1.  时间复杂度 O(log n).
2. 第一时间想到的是双指针
3. 第二时间想到的是 Binary Search



做题中：

1. 首先从数组最中间的数开始
2. 分为左右两个指针
3. 如果 idx_left 左边的 element 比 idx_left大, 则 next_left 是 idx_left 往左移 1
4. 如果 idx_left 左边的 element 比 idx_left小, 则 next_left 是 idx_left 往左移 2
5. 对于 idx_right 也是一样的道理，不过是反过来



做题后：

1.  AC beat 100%， 但是这个真的是 O(log n) 的复杂度吗？

