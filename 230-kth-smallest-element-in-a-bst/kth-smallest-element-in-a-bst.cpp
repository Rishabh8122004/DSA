class Solution {
public:
    void solve(TreeNode* root,int & k,vector<int>&ans){
        if(!root || ans.size() == k)return;
        if(root->left && ans.size()<k)solve(root->left,k,ans);
        if(ans.size()<k)ans.push_back(root->val);
        if(root->right && ans.size()<k)solve(root->right,k,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,k,ans);
        cout<<ans.size();
        return ans.back();
    }
};