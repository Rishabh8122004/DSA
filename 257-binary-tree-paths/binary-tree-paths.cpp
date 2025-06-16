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
    void solve(TreeNode* root,vector<string> &ans,string a){
        if(!root->left && !root->right){if(!a.empty() && a.back()!='>')a+="->";a+=to_string(root->val); ans.push_back(a);return;}
        if(!a.empty() && a.back()!='>')a+="->";
        a += to_string(root->val);
        if(root->left)solve(root->left,ans,a); 
        if(root->right)solve(root->right,ans,a);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return{""};
        vector<string>ans;
        solve(root,ans,"");
        return ans;
    }
};