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
    void bottom_left(TreeNode* root,int level,pair<int,int> &ans){
        if(!root)return;
        if(level>ans.second){ans = {root->val,level};}
        bottom_left(root->left,level+1,ans);
        bottom_left(root->right,level+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
       pair<int,int>ans;
       ans = {root->val,1};
       bottom_left(root,1,ans);
       return ans.first; 
    }
};