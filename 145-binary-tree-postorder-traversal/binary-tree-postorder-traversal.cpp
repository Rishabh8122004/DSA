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
    // void postorder(TreeNode* root,vector<int>&v){
    //     if(!root)return;
    //     postorder(root->left,v);
    //     postorder(root->right,v);
    //     v.push_back(root->val);
    //     return;
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>v;
        // postorder(root,v);
        // return v;

        //iterative method using stack -->
        stack<TreeNode*>st;
        vector<int>v;
        if(root) st.push(root);
        while(st.size()){
            TreeNode* temp = st.top();st.pop();
            v.push_back(temp->val);
            if(temp->left)st.push(temp->left);
            if(temp->right)st.push(temp->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};