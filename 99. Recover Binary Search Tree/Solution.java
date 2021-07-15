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
    TreeNode firstElement = null;
    TreeNode secondElement = null;
    TreeNode prev = new TreeNode(Integer.MIN_VALUE);
    
    public void recoverTree(TreeNode root) {
        traversal(root);
        int temp = firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val = temp;
    }
    
    public void traversal(TreeNode root)
    {
        if(root == null)
        {
            return;
        }
        
        traversal(root.left);  

        if(firstElement == null)
        {
            if(root.val < prev.val)
            {
                firstElement = prev;
            }
        }
        
        if(firstElement != null)
        {
            if(root.val < prev.val)
            {
                secondElement = root;
            }
        }
        
        prev = root;
        
        traversal(root.right);  
    }
}