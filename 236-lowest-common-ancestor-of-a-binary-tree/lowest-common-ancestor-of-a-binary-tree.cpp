class Solution {
public:
    bool exist(TreeNode* root, TreeNode* & p){
        if(!root)return false;
        if(root == p)return true;
        return exist(root->left,p)||exist(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exist(root->left,p) && exist(root->left,q))return lowestCommonAncestor(root->left,p,q);
        else if(exist(root->right,p) && exist(root->right,q))return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};