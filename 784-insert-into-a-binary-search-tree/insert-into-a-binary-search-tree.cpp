class Solution {
public:
    void insert(TreeNode* &root,TreeNode* v){
        if(!root->left && v->val < root->val){
            root->left = v;
            return;
        }
        else if(!root->right && v->val > root->val){
            root->right = v;
            return;
        }
        if(v->val < root->val && root->left)insert(root->left,v);
        else if(v->val > root->val && root->right)insert(root->right,v);
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* v = new TreeNode(val);
        if(!root)return v;
        insert(root,v);
        return root;
    }
};