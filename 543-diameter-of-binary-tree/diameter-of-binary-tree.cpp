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
    int levels(TreeNode *root){
        if(root == NULL)return 0;
        int ans = 1+max(levels(root->left),levels(root->right));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int ans = 0;
        ans = max(ans,levels(root->left)+levels(root->right));
        ans = max(ans,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        return ans;
    }
};