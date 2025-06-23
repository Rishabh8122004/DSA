class Solution {
public:
    void findpath(TreeNode* root,TreeNode* &p, vector<TreeNode*>&v){
        if(!root)return;
        v.push_back(root);
        if(root->val == p->val)return;
        if(p->val<root->val)findpath(root->left,p,v);
        else findpath(root->right,p,v);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v,w;
        findpath(root,p,v);
        findpath(root,q,w);
        int i = 0;
        TreeNode*ans;
        while(i<v.size()&&i<w.size()&& v[i] == w[i]){
            ans = v[i];
            i++;
        }
        return ans;
    }
};