class Solution {
public:
    bool check(TreeNode* a,TreeNode* b){
        if(!a && !b)return true;
        else if((!a && b) || (a && !b))return false;
        if(a && b){
            if(a->val != b->val)return false;
        }
        return ((check(a->left,b->right)) && check(a->right,b->left));
    }
    bool isSymmetric(TreeNode* root) {
       if(!root)return true;
       return check(root->left,root->right);
    }
};