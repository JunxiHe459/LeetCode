class Solution {

  public int[][] kClosest(int[][] points, int k) {
    Queue<int[]> minHeap = new PriorityQueue<>(
      (o1, o2) ->
        (o1[0] * o1[0] + o1[1] * o1[1]) - (o2[0] * o2[0] + o2[1] * o2[1])
    );

    for (int[] cor : points) {
      minHeap.offer(new int[] { cor[0], cor[1] });
    }

    int[][] re = new int[k][2];
    while (k > 0) {
      k--;
      re[k] = minHeap.poll();
    }
    return re;
  }
}
