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
    int MOD = 1000000007;
    int getsum(TreeNode* &root){
        if(!root)return 0;
        root->val+=getsum(root->left);
        root->val+=getsum(root->right);
        return root->val;
    }
    void solve(TreeNode* root,long long &ans,long long &totalsum){
        if(!root)return;
        ans = max(ans,root->val*(totalsum-root->val));
        solve(root->left,ans,totalsum);
        solve(root->right,ans,totalsum);
    }
    int maxProduct(TreeNode* root) {
        long long sum = 0;
        long long totalsum = getsum(root);
        long long ans = 0;
        solve(root,ans,totalsum);
        return ans%MOD;
    }
};