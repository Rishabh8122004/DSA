class Solution {
public:
    int levels(TreeNode* root){
        if(!root)return 0;
        int n = 1+max(levels(root->left),levels(root->right));
        return n;
    }
    void nthlevelnodes(TreeNode* root, vector<vector<int>> &ans,int a){
        if(!root){return;}
        ans[a-1].push_back(root->val);
        nthlevelnodes(root->left,ans,a+1);
        nthlevelnodes(root->right,ans,a+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>>ans(n);
        int a = 1;
        nthlevelnodes(root,ans,a);
        vector<int>v;
        for(int i = 0;i<ans.size();i++){
            v.push_back(ans[i][ans[i].size()-1]);
        }
        return v;
    }
};