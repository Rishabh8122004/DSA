class Solution {
public:
    void solve(TreeNode* root,vector<int>v,vector<vector<int>>&ans,int sum,int &ts){
        if(!root){return;}
        v.push_back(root->val);
        if( (!root->left && !root->right) && sum+root->val == ts){ans.push_back(v);}
        solve(root->left,v,ans,sum+root->val,ts);
        solve(root->right,v,ans,sum+root->val,ts);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(root,v,ans,0,ts);
        return ans;
    }
};