class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (root->val>=min(p->val,q->val) && root->val<=max(p->val,q->val)))return root;
        else if(root->val>min(p->val,q->val) && root->val>max(p->val,q->val))return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};