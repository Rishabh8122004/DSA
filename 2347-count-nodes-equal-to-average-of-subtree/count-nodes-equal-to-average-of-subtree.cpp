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
    int ans = 0;
    void solve(TreeNode* root,int & sum,int &non){
        if(!root)return;
        int ls = 0,rs = 0,nr = 0,nl = 0;
        solve(root->left,ls,nl);
        solve(root->right,rs,nr);
        sum+=root->val + ls + rs;
        non+= (1+nl+nr);
        if(root->val == floor(sum/non)) ans+=1;
        return;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        int non = 0;//no. of nodes
        solve(root,sum,non);
        return ans;
    }
};