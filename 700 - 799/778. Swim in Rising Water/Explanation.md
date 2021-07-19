# Swim in Rising Water

做题前：

1. 题目的意思就是：找到一条从 2D array 左上角到右下角的路线（只能上下左右走，不能斜着），使得这条路线经过的所有的点的最大值，最小。例如： 2 -> 1 -> 7-> 5, 最大值为 7
2. ==条件2==：这个题还有个条件，就是这个 $$n\times n$$ 的矩阵里面，每个元素的取值为 [0, n^2 - 1]，且每个值只出现一次。（反正我读题是没读出来，看了别人的解析才知道）；/
3. 一共 3 种解法，分别是 Binary Search，Union Find，Dijkstra



做题中：

1.  Binary Search:  注意 right = mid , left = mid + 1 不是 left = mid，不然会 infinity loop

2.  Union Find:

   1.  Union Find 的简单实现，```root(n), connected(n, m), merger(n, m)```。
   2. 在知道“条件2”的情况下，把二维数组转换成一维数组，从而方便我们使用 UnionFind 。在代码中的 6 - 10 行，```index[n] = n 在 grid 中的位置```。
   3. 准备工作完成后就水到渠成了。从 0 到 n^2 - 1 遍历数组，当其中一个值使得 grid 的左上角和右下角用同一个 parent 时（使用 UnionFind 的 connected 来判断)，证明这个值就是最小的使得grid 的左上角和右下角连通的值。

3. Dijkstra：

   1. 为什么能用 Dijkstra？ 因为没有权值为负数的单元格，```grid[i][j] >= 0```.

   2. 创建一个 Distance 2D数组来表示到每个位置需要的最小的时间 T。 初始化每个位置的 distance 为 ```Integer.MAX_VALUE```。将 ```Distance[0][0]```初始化为```grid[0][0]```因为我们从这里开始。

   3. 假设我们在位置 ```(x, y)```，判断一个相邻的位置```(new_x, new_y)```。存在 3 种情况：

      1. ```Distance[new_x][new_y] < Math.max(Distance[x][y], Grid[new_x][new_y])```,在这种情况下，```Distance[new_x][new_y]```已经取到更优解（更小的值），无需做任何事情。
      2. ```Distance[new_x][new_y] > Distance[x][y] > Grid[new_x][new_y]```在这种情况下，```Distance[new_x][new_y]```还未取到更优解（更小的值），需要进行优化。```Distance[x][y] > Grid[new_x][new_y]```意味着到```(x, y)```比```Grid[new_x][new_y]```本身的值要大，这可能使因为在去到```(x, y)```之前，需要经过一个```grid[old_x][old_y]```，而这个点需要更大的值才能经过。所以这个时候我们让```Distance[new_x][new_y] = Distance[x][y] ```
      3. ```Distance[new_x][new_y] > Grid[new_x][new_y] > Distance[x][y] ```在这种情况下，```Distance[new_x][new_y]```还未取到更优解（更小的值），需要进行优化。```Grid[new_x][new_y] > Distance[x][y]```意味着到 ```Gird[x][y]```本身的值比到```(x,y)```还要大，因此我们需要在 ```(x,y)```等到 ```t =  Gird[x][y]```才能过去，所以```Distance[new_x][new_y] = Grid[new_x][new_y]```

   4. 综上所述，我们得到

      ```java
       if(Math.max(distance[x][y], grid[new_x][new_y]) < distance[new_x][new_y]) {
                distance[new_x][new_y] = Math.max(distance[x][y], grid[new_x][new_y]);
                minHeap.offer(new int[] { new_x, new_y });
       }
      ```

      



做题后：

1. 个人更喜欢 Binary Search 的做法，写起来更轻松。
2. 分析题目很重要，这个题讲了一大堆故事，就是为了告诉你 “找到一条从 2D array 左上角到右下角的路线（只能上下左右走，不能斜着），使得这条路线经过的所有的点的最大值，最小”。

