# Find Peak Element O(n)

做题前：

1.  时间复杂度 O(log n).
2. 第一时间想到的是双指针
3. 第二时间想到的是 Binary Search



做题中：

1. 二分法的复杂度是 O(log n).

2. Bianry Search 需要 Sorted Array 来找 Global Maximum

3. 但对于 Local Maximum， 就不需要 Sorted 了

4. 产生 Local Maximum 的 4 种情况：

   1. 单调递增，如 [1, 2, 3, 4, 5] 则最右边是 Local Maximum
   2. 单调递减，如 [5, 4, 3, 2, 1] 则最左边是 Local Maximum
   3. 先增后减，如 [3, 4, 5, 2, 1] 则由增到减的点为 Local Maximum
   4. 先减后增，如 [5, 4, 1, 2, 3] 则最左边或者最右边是 Local Maximum 

5. 因此， 得到

   ```python
               # 左小右大，从减到增
       		# 因为没法判断最左边的element在哪里，只好放弃左边
               # 选择让 left = mid + 1 去找右边的 Local Maximum
       		if (nums[mid] < nums[mid + 1]):
                   left = mid + 1
               # 左大右小，从增到减
               # 因此让 right = mid， 来寻找区间 [left, mid] 的 Local Maximum
               else:
                   right = mid
   ```

   

做题后：

1.  找机会熟悉一下各种查找和排序算法 : /

