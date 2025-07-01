class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        if(!root)return NULL;
        while(root){
            if(root->val < lo){
                root = root->right;
            }
            else if(root->val > hi){
                root = root->left;
            }
            else break;
        }
        if(!root)return NULL;
        while(root->left){
            if(root->left->val < lo){
                root->left = root->left->right;
            }
            else if(root->left->val > hi){
                root->left = root->left->left;
            }
            else break;
        }
        while(root->right){
            if(root->right->val < lo){
                root->right = root->right->right;
            }
            else if(root->right->val > hi){
                root->right = root->right->left;
            }
            else break;
        }
        trimBST(root->left,lo,hi);
        trimBST(root->right,lo,hi);
        return root;
    }
};