class Solution {

  public int swimInWater(int[][] grid) {
    int n = grid.length;

    Queue<int[]> minHeap = new PriorityQueue<>(
      (o1, o2) -> grid[o1[0]][o1[1]] - grid[o2[0]][o2[1]]
    );
    minHeap.offer(new int[] { 0, 0 });

    boolean visited[][] = new boolean[n][n];

    int[][] distance = new int[n][n];
    for (int[] row : distance) {
      Arrays.fill(row, n * n);
    }

    distance[0][0] = grid[0][0];

    int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    while (!minHeap.isEmpty()) {
      int[] temp = minHeap.poll();
      int x = temp[0];
      int y = temp[1];
      if (visited[x][y]) {
        continue;
      }

      visited[x][y] = true;
      if (x == n - 1 && y == n - 1) {
        return distance[x][y];
      }

      for (int[] d : dir) {
        int new_x = x + d[0];
        int new_y = y + d[1];
        if (
          new_x >= 0 &&
          new_x < n &&
          new_y >= 0 &&
          new_y < n &&
          !visited[new_x][new_y] &&
          Math.max(distance[x][y], grid[new_x][new_y]) < distance[new_x][new_y]
        ) {
          distance[new_x][new_y] = Math.max(distance[x][y], grid[new_x][new_y]);
          minHeap.offer(new int[] { new_x, new_y });
        }
      }
    }

    return -1;
  }
}
