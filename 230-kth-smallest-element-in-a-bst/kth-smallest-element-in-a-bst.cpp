class Solution {
public:
    void solve(TreeNode* root,int & k,int &ans){
        if(!root || k==0)return;
        if(root->left && k>0)solve(root->left,k,ans);
        if(k>0)ans=root->val;
        k--;
        if(root->right && k>0)solve(root->right,k,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        solve(root,k,ans);
        return ans;
    }
};