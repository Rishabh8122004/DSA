class Solution {
public:
    void solve(TreeNode*& root){
        if(!root)return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        solve(root->left);
        solve(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) { if(!root)return root;
        TreeNode* temp = root;
        solve(root);
        return root;
    }
};