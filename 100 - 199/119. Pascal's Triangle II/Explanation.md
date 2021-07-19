# Pascal's Triangle II

做题前：

1. 一开始想用递归来做的，代码也比较好写。不过递归会超过 Time Limit
2. 学习了一下 Iterative 的写法



做题中：

1.  Iterative 的精髓在于，先创建一个 size = rowIndex + 1 的数组， 然后在外层循环用这个数组依次模拟从 0 到 size 的 每一行在 Pascal Triangle 中的样子。在里层循环呢，则是更新这个数组在每一行的值。总的来说就是，每次 update 时， 这个数字的前 n 个数字，组成了 Pascal Triangle的第 n 行。当运行到最后一次循环时，前 rowIndex + 1 个数字，组成了 Pascal Triangle 的第 n + 1 行， 也就是我们需要 return 的那一行。

   eg：

   rowIndex = 3

   先创建一个 size 为 4 的数组，[1, 0, 0, 0]，最左边的值肯定为 1，这是 Pascal Triangle 的第 1 行

   然后为 [1, 1, 0, 0]，这是 Pascal Triangle 的第 2 行

   然后为 [1, 2, 1, 0]，这是 Pascal Triangle 的第 3 行

   然后为 [1, 3, 3, 1]，这是 Pascal Triangle 的第 4 行

   return [1, 3, 3, 1]



做题后：

1. 为什么 Inner loop 是

   ```c++
    (int j = i; j > 0; --j)
   ```

   而不是

   ```c++
    (int j = 1; j <= i; ++j)
   ```

   我们知道，在帕斯卡三角中，第 n 行的第 k 个元素的值为 第 n - 1行的 第 k 个元素 + 第 n - 1行的 第 k - 1 个元素.

   ```c++
   Pascal[n][k] = Pascal[n - 1][k - 1] + Pascal[n - 1][k]
   ```

   我们不能从前往后更新数组，对于这道题而言, ``` re[j]```的值取决于```re[j - 1]```和``re[j]``.

   因此，我们必须从后往前更新数组，因为改变```re[j+1]```的值不会影响新的```re[j]```.

2. 为什么```re[k] += re[k - 1]```?

   这是因为 ```Pascal[n][k] = Pascal[n - 1][k - 1] + Pascal[n - 1][k]```,在这里

   ```Pascal[n - 1][k - 1] =  re[k - 1]```

   ```Pascal[n - 1][k] =  re[k] ```

   ```re[k] = Pascal[n - 1][k - 1] + Pascal[n - 1][k] = re[k - 1] + re[k]```

   所以我们得到```re[k] += re[k - 1]```

