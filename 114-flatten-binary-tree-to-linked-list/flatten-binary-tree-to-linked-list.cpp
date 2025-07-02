class Solution {
public:
    TreeNode* flatthetree(TreeNode* &root){
        if(!root)return root;
        TreeNode* l = flatthetree(root->left);
        TreeNode* r = flatthetree(root->right);
        root->right = l;
        root->left = NULL;
        TreeNode* temp = root;
        while(temp->right)temp = temp->right;
        temp->left = NULL;
        temp->right = r;
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        root = flatthetree(root);
        return;
    }
};