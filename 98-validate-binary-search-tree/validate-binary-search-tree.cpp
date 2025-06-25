class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(!root)return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        if(v.empty())return true;
        int m = v[0];
        for(int i = 1;i<v.size();i++){if(v[i]<=m)return false;m = max(m,v[i]);}
        return true;
    }
};