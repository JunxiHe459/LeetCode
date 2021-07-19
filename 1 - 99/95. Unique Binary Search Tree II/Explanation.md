# Unique Binary Search Tree II

做题前：

1.  对于任意[1, n], 选中 K 作为root来说，左边的树只能为[1, K - 1]，右边的树则为[K + 1, n]

   

做题中：

1. ```java
               List<TreeNode> left = helper(min, i - 1);
               List<TreeNode> right = helper(i + 1, max);
   ```

2. 仔细思考 min 和 max 的含义



做题后：

1. 这个题做完了感觉思路还是不难，就是不知道为什么做的时候一直想不出来。

2. 从二叉树的定义入手，得到左边的取值范围是[min, K - 1], 左边的是[K + 1, max]。

3. 然后用递归的思路，去分解[min, max]。题目规定一开始，min = 1 以及 max = N。[1, N]种有N种Root的取值，每种Root的取值都对应着上述的[min, K - 1] 和 [K + 1, max]。每个[min, K - 1] 和 [K + 1, max] 又能看成一个新的 [min, max] 组合。

4. Break Condition：举例 [1, 2] -> [1, 1] -> [1, 0]

   ​															 	 -> [2, 1]

   ​												   ->  [2, 2] -> [2, 1]

   ​                                                                   -> [3, 2]

   可以得到 [min, max] 的 break condition 为 min > max

 
