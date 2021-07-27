# Minimum Time Difference

做题前：

1. 先从小到大排序，再挨个比较
2. 写一个方法来比较两个时间



做题中：

1. 先将时间从“24：00”转化为两个 int

   ```c++
           int t1 = stoi(time1.substr(0,2));
           int t2 = stoi(time1.substr(3,2));
           int t3 = stoi(time2.substr(0,2));
           int t4 = stoi(time2.substr(3,2));
   ```

2. 再比较

   ```c++
           int t  = abs(t3 - t1) * 60 + t4 - t2;
           return min(24*60 - t, t);
   ```

   



做题后：

1. java 用 compareTo 比较，C++ 用 compare 来比较
2. 小于 return < 0
3. 等于 return =0
4. 大于 return > 0

