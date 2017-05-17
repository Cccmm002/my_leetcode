// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
//
//
// Example:
//
// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13
//
// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int calc(TreeNode root, int plus) {
        if(root.left == null && root.right == null) {
            root.val += plus;
            return root.val - plus;
        }
        else if(root.right == null) {
            int l = calc(root.left, plus + root.val);
            int res = l + root.val;
            root.val += plus;
            return res;
        }
        else if(root.left == null) {
            int r = calc(root.right, plus);
            int res = r + root.val;
            root.val += plus + r;
            return res;
        }
        else {
            int r = calc(root.right, plus);
            int l = calc(root.left, plus + root.val + r);
            int res = root.val + r + l;
            root.val += plus + r;
            return res;
        }
    }
    
    public TreeNode ConvertBST(TreeNode root) {
        if(root == null) 
            return null;
        int val = calc(root, 0);
        return root;
    }
}
