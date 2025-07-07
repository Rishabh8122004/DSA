class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    void fillthetree(TreeNode* root,vector<int>&v,int& idx){
        if(!root)return;
        fillthetree(root->left,v,idx);
        root->val = v[idx++];
        fillthetree(root->right,v,idx);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int idx = 0;
        fillthetree(root,v,idx);
        return;
    }
};