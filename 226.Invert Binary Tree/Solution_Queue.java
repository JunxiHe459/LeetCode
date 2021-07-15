/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

  public TreeNode invertTree(TreeNode root) {
    if (root == null) {
      return null;
    }

    Queue<TreeNode> q = new LinkedList();
    q.offer(root);

    while (!q.isEmpty()) {
      TreeNode r = q.poll();

      TreeNode temp = r.left;
      r.left = r.right;
      r.right = temp;

      if (r.left != null) {
        q.offer(r.left);
      }
      if (r.right != null) {
        q.offer(r.right);
      }
    }

    return root;
  }
}
