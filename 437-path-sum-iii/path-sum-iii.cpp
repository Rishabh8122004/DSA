class Solution {
public:
    void solve(TreeNode* root,int &ans,long long sum,int &ts){
        if(!root ){return;}
        if(sum+root->val == ts){ans++;}
        solve(root->left,ans,sum+root->val,ts);
        solve(root->right,ans,sum+root->val,ts);
        return;
    }
    int pathSum(TreeNode* root, int ts) {
        if(!root)return 0;
        int ans = 0;
        solve(root,ans,0,ts);
        ans+=pathSum(root->left,ts);
        ans+=pathSum(root->right,ts);
        return ans;
    }
};