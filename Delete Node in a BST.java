//  450. Delete Node in a BST
//  https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
    TreeNode cal(TreeNode r) {
        TreeNode c = r;
        while(c != null && c.left != null) {
            c = c.left;
        }
        return c;
    }
    
    public TreeNode deleteNode(TreeNode root, int k) {
        if (root == null) {
            return root;
        }
        else if(k < root.val) {
            root.left = deleteNode(root.left, k);
        }
        else if(k > root.val) {
            root.right = deleteNode(root.right, k);
        }
        else {
            if (root.left == null) {
                return root.right;
            }
            else if (root.right == null) {
                return root.left;
            }
            else {
                TreeNode t = cal(root.right);
                root.val = t.val;
                root.right = deleteNode(root.right, t.val);   
            }
        }
        return root;
    }
}
