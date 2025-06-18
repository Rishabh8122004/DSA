/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void nth_order(TreeNode* root,vector<pair<int,int>> &v,int a){
        if(!root)return;
        v.push_back({a,root->val});
        nth_order(root->left,v,a+1);
        nth_order(root->right,v,a+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return ans;
    }
};