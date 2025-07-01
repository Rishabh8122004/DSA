class Solution {
public:
    void link(TreeNode* root,TreeNode*& node){
        while(root->left)root = root->left;
        root->left = node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val == key){
            if(!root->left && !root->right)return NULL;
            else if(!root->left && root->right)return root->right;
            else if(root->left && !root->right)return root->left;
            else{
                link(root->right,root->left);
                return root->right;
            }
        }
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};