# 278. First Bad Version

做题前：

1. 二分法




做题中：

1. ``` c++
       int firstBadVersion(int n) {
           long left = 1;
           long right = n;
           
           while(left <= right) {
               long mid = (left + right) / 2;
               
               if(isBadVersion(mid)) {
                   right = mid - 1;
               } else {
                   left = mid + 1;
               }
           }
           
           return left;
       }
   ```

   为什么这里可以直接 return left ?

   因为给定了这堆数据里面一定有我们需要的，也就是说，没有 return -1 的情况

2.  如果数据太大，有可能会有 (left + right) > max(int)，也就是会出现 overflow 的情况

    1.  解决办法 1: 用 long
    2.  **```int mid = left + (right - left ) / 2 ```   推荐这种做法**

做题后：

1. 

