class Solution {
public:
    int height(TreeNode* root){
        if(!root)return 0;
        int h = 1 + max(height(root->left),height(root->right));
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int h1 = 0,h2 = 0;
        h1 = height(root->left);
        h2 = height(root->right);
        if(abs(h1-h2)>1)return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};