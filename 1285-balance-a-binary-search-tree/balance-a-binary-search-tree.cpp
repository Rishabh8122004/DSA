class Solution {
public:
    void traverse(TreeNode* root,vector<int>& v){
        if(!root)return;
        v.push_back(root->val);
        traverse(root->left,v);
        traverse(root->right,v);
        return;
    }
    TreeNode* build(vector<int>&v,int lo,int hi){
        if(lo>hi)return NULL;
        int mid = (lo+(hi-lo)/2);
        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(v,lo,mid-1);
        root->right = build(v,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        traverse(root,v);
        sort(v.begin(),v.end());
        return build(v,0,v.size()-1);
    }
};