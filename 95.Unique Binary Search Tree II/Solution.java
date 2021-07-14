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

  public List<TreeNode> generateTrees(int n) {
    return helper(1, n);
  }

  public List<TreeNode> helper(int min, int max) {
    List<TreeNode> result = new ArrayList<TreeNode>();
    if (min > max) {
      return result;
    }

    for (int i = min; i <= max; i++) {
      List<TreeNode> left = helper(min, i - 1);
      List<TreeNode> right = helper(i + 1, max);

      if (left.size() == 0 && right.size() == 0) {
        TreeNode root = new TreeNode(i);
        result.add(root);
      } else if (left.size() == 0) {
        for (TreeNode r : right) {
          TreeNode root = new TreeNode(i);
          root.right = r;
          result.add(root);
        }
      } else if (right.size() == 0) {
        for (TreeNode l : left) {
          TreeNode root = new TreeNode(i);
          root.left = l;
          result.add(root);
        }
      } else {
        for (TreeNode l : left) {
          for (TreeNode r : right) {
            TreeNode root = new TreeNode(i);
            root.left = l;
            root.right = r;
            result.add(root);
          }
        }
      }
    }

    return result;
  }
}
