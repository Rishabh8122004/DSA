class Solution {
public:
    void traverse(TreeNode* root,vector<TreeNode*>& v){
        if(!root)return;
        traverse(root->left,v);
        v.push_back(root);
        traverse(root->right,v);
        return;
    }
    TreeNode* build(vector<TreeNode*>&v,int lo,int hi){
        if(lo>hi)return NULL;
        int mid = (lo+(hi-lo)/2);
        TreeNode* root = v[mid];
        root->left = build(v,lo,mid-1);
        root->right = build(v,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>v;
        traverse(root,v);
        return build(v,0,v.size()-1);
    }
};