class Solution {
public:
    void nth_order(TreeNode* root,vector<pair<int,int>> &v,int a){
        if(!root)return;
        v.push_back({a,root->val});
        nth_order(root->left,v,a+1);
        nth_order(root->right,v,a+1);
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<pair<int,int>>v;
        int a = 0;
        nth_order(root,v,a);
        int m = 0;
        for(int i = 0;i<v.size();i++){
           m = max(v[i].first + 1,m);
        }
        vector<vector<int>>ans(m);
        for(int i = 0;i<v.size();i++){
           ans[v[i].first].push_back(v[i].second);
        }
        for(int i = 1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};