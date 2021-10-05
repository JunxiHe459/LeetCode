# Diagonal Traverse

假设给定的矩阵是 m x n

![image-20211005174443840](/Users/junxihe/Desktop/LeetCode/400 - 499/498. Diagonal Traverse/image-20211005174443840.png)

做题前：

1. 首先是一共有几次 Diagonal Traverse ？

   答：一共有 m + n - 1 次，一共 5 次。 对应图上的 1, 4, 7, 8, 9

做题中：

1. 对于第 i 个 Diagonal 而言，假设坐标为 (x,y):

      1. x + y  == i (废话)

      2. 如果 i 是奇数，那么是从左下往右上走 -> x++, y--

            所以：

            ```c++
            // Find all correct starting index of each diagonal traverse
            		int y = (i < n) ? i : n - 1;
                    int x = (i - n + 1 > 0) ? i - n + 1 : 0;
                    while(x < m && y >= 0)
                    {
                        result.push_back(mat[x][y]);
                        x++;
                        y--;
                    }
            ```

            

      3. 如果 n 是偶数，那么是从右上往左下走 -> x--, y++

            所以：

            ```c++
            // Find all correct starting index of each diagonal traverse
                    int x = (i < m) ? i : m - 1;
                    int y = (i - m + 1 > 0) ? i - m + 1 : 0;
                    while(y < n && x >= 0)
                    {
                        result.push_back(mat[x][y]);
                        x--;
                        y++;
                    }
            ```

            

      

做题后：

1.  

