
class Solution {
public:
    // void preorder(TreeNode* root,vector<int>&v){
    //     if(!root)return;
    //     v.push_back(root->val);
    //     preorder(root->left,v);
    //     preorder(root->right,v);
    //     return;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        // vector<int>v;
        // preorder(root,v);
        // return v;
        
        //iterative method using stack -->
        stack<TreeNode*>st;
        vector<int>v;
        st.push(root);
        while(st.size()){
            TreeNode* temp = st.top();st.pop();
            v.push_back(temp->val);
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
        }
        return v;
    }
};