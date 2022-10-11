class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * curr= new TreeNode(-1);
        curr=root;
        while(root){
            if(p->val>curr->val and q->val>curr->val ) curr=curr->right;
            else if(p->val<curr->val and q->val<curr->val ) curr=curr->left;
            else return curr;
        }
       return curr; 
    }
};
