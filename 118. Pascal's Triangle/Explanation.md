# Pascal's Triangle

做题前：

1. 帕斯卡三角
2. $(x + y)^n$ 每一项的常数



做题中：

1. Easy

   

2. ```c++
               temp[0] = 1;
               temp[i - 1] = 1;
               for(int j = 1; j < i - 1; ++j)
               {
                   temp[j] = re[i-2][j-1] + re[i-2][j]; 
               }
   ```

   有点儿 Hard Coding 的感觉

做题后：

1. 参考 119. Pascal's Triangle II

