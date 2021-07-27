# 题目名字

做题前：

1. bit shift



做题中：

1. 发现了一种天才的做法：

   1. ```c++
              int total = 0;
              while(n)
              {
                  // Genius
                  n &= (n-1);
                  total++;
              }
              return total;
      ```

   2. ==一个数减去 1，会使这个数的第一个不为 0 的bit变成 0==



做题后：

1. 

