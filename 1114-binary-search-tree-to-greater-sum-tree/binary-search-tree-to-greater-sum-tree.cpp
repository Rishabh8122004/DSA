class Solution {
public:
    void solve(TreeNode* root,int & sum){
        if(!root)return;
        if(root->right)solve(root->right,sum);
        root->val += sum;
        sum += (root->val-sum);
        if(root->left)solve(root->left,sum);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return root;
    }
};